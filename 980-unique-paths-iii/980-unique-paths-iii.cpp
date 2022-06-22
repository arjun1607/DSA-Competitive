class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int ex, int ey, vector<vector<bool>> &vis){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j]==true){
            return 0;
        }
        
        if(i==ex && j==ey){
            int c=0;
            for(int p=0;p<vis.size();p++){
                for(int q=0;q<vis[0].size();q++){
                    if(vis[p][q] == false) c++;
                }
            }
            
            if(c==1) return 1;
            return 0;
        }
        
        vis[i][j]=true;
        int up=dfs(grid, i-1, j, ex, ey, vis);
        int left=dfs(grid, i, j-1, ex, ey, vis);
        int down=dfs(grid, i+1, j, ex, ey, vis);
        int right=dfs(grid, i, j+1, ex, ey, vis);
        vis[i][j]=false;
        
        return up+left+down+right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int sx, sy, ex, ey;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sx=i, sy=j;
                }
                else if(grid[i][j]==2){
                    ex=i, ey=j;
                }
                else if(grid[i][j]==-1){
                    vis[i][j]=true;
                }
            }
        }
        return dfs(grid, sx, sy, ex, ey, vis);
    }
};