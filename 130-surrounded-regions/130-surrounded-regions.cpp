class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &vis){
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size() || vis[i][j] || grid[i][j]=='X') return;
        vis[i][j]=true;
        dfs(grid, i-1, j, vis);
        dfs(grid, i, j-1, vis);
        dfs(grid, i+1, j, vis);
        dfs(grid, i, j+1, vis);
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]=='O' && !vis[i][j])
                    dfs(grid, i, j, vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && vis[i][j]==false)
                    grid[i][j]='X';
            }
        }
    }
};