class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][i]=grid[i][j];
            }
        }
        return ans;
    }
};