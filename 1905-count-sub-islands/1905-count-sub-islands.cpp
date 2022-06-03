class Solution {
public:
    void dfs(vector<vector<int>>& grid2, vector<vector<int>>& grid1, int i, int j, bool &same){
        if(i<0 || i==grid1.size() || j<0 || j==grid1[0].size() || grid2[i][j]==0) return;
        if(grid2[i][j]!=grid1[i][j]){
            same=false;
            return;
        }
        grid2[i][j]=0;
        dfs(grid2, grid1, i-1, j, same);
        dfs(grid2, grid1, i, j-1, same);
        dfs(grid2, grid1, i+1, j, same);
        dfs(grid2, grid1, i, j+1, same);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(), m=grid1[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid1[i][j]==1 && grid2[i][j]==1){
                    bool same=true;
                    dfs(grid2, grid1, i, j, same);
                    if(same) count++;
                }
            }
        }
        return count;
    }
};