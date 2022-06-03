class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int &x, int &y){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==0) return;
        grid[i][j]=0;
        if(i>=x && j>=y){
            x=i; y=j;
        }
        dfs(grid, i-1, j, x, y);
        dfs(grid, i, j-1, x, y);
        dfs(grid, i+1, j, x, y);
        dfs(grid, i, j+1, x, y);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int k=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans.push_back({});
                    ans[k].push_back(i);
                    ans[k].push_back(j);
                    int x=i, y=j;
                    dfs(grid, i, j, x, y);
                    ans[k].push_back(x);
                    ans[k].push_back(y);
                    k++;
                }
            }
        }
        return ans;
    }
};