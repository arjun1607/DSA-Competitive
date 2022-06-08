class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int prev, int color, vector<vector<bool>>& vis){
        vis[i][j]=true;
        grid[i][j]=color;
        int count=0; // kidhar kidhar call lag sakti h oska count
        
        if(i-1>=0 && (grid[i-1][j]==prev || vis[i-1][j])){
            count++;
            if(!vis[i-1][j]) dfs(grid, i-1, j, prev, color, vis);
        }
        if(j-1>=0 && (grid[i][j-1]==prev || vis[i][j-1])){
            count++;
            if(!vis[i][j-1])  dfs(grid, i, j-1, prev, color, vis);
        }
        if(i+1<grid.size() && (grid[i+1][j]==prev || vis[i+1][j])){
            count++;
            if(!vis[i+1][j])  dfs(grid, i+1, j, prev, color, vis);
        }
        if(j+1<grid[0].size() && (grid[i][j+1]==prev || vis[i][j+1])){
            count++;
            if(!vis[i][j+1])  dfs(grid, i, j+1, prev, color, vis);
        }
        
        if(count==4)
            grid[i][j]=prev;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r, int c, int color) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis (n, vector<bool>(m, false));
        dfs(grid, r, c, grid[r][c], color, vis);
        return grid;
    }
};