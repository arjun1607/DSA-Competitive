class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==1) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
        if(memo[i][j]!=-1) return memo[i][j];
        return memo[i][j]=helper(grid, i, j+1, memo)+helper(grid, i+1, j, memo);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> memo(n, vector<int> (m, -1));
        return helper(grid, 0, 0, memo);
    }
};