class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j] == 0 || vis[i][j]) return;
        vis[i][j]=true;
        grid[i][j]= 0;
        dfs(grid, i+1, j, vis);
        dfs(grid, i-1, j, vis);
        dfs(grid, i, j+1, vis);
        dfs(grid, i, j-1, vis);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(); 
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( (i==0 || i==n-1 || j==0 || j==m-1 ) && grid[i][j]==1){
                    dfs(grid, i, j, vis);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};