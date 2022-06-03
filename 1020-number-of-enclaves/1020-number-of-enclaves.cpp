class Solution {
public:
    int x[4]={-1,0,1,0};
    int y[4]={0,-1,0,1};
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==0) return;
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int ni=i+x[k], nj=j+y[k];
            dfs(grid, ni, nj);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // boundary par jitne 1s h unpr dfs lagado aur make all connected 1s to 0
        // after that simply calculate the count of ones
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                    dfs(grid, i, j);
                }
            }
        }
        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};