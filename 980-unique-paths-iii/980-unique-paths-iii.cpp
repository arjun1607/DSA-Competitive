class Solution {
public:
    int empty=1;
    int dfs(vector<vector<int>>& grid, int i, int j,int count){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==-1){
            return 0;
        }
        
        if(grid[i][j]==2){
            if(count==empty) return 1;
            return 0;
        }
        
        grid[i][j]=-1;
        int up=dfs(grid, i-1, j, count+1);
        int left=dfs(grid, i, j-1, count+1);
        int down=dfs(grid, i+1, j, count+1);
        int right=dfs(grid, i, j+1, count+1);
        grid[i][j]=0;
        
        return up+left+down+right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int sx, sy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sx=i, sy=j;
                }else if(grid[i][j]==0){
                    empty++;
                }
            }
        }
        return dfs(grid, sx, sy, 0);
    }
};