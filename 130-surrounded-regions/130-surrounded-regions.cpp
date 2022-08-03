class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j] || grid[i][j]=='X') return;
        vis[i][j]=true;
        dfs(i+1, j, grid, vis);
        dfs(i-1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i, j-1, grid, vis);
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j== 0 || i==n-1 || j==m-1)  &&  grid[i][j]=='O'){
                    dfs(i, j, grid, vis);
                } 
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && !vis[i][j]){
                    grid[i][j] = 'X';
                } 
            }
        }
        
    }
};