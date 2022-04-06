class Solution {
public:
    int memo(int i, int j1, int j2, vector<vector<int>> &grid, int m, int n,
                                       vector<vector<vector<int>>> &dp){
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e9;

        if (i == m - 1) {
            if (j1 == j2)
              return grid[i][j1];
            else
              return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = INT_MIN;
          for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
              int ans;
              if (j1 == j2)
                ans = grid[i][j1] + memo(i + 1, j1 + dj1, j2 + dj2, grid, m, n, dp);
              else
                ans = grid[i][j1] + grid[i][j2] + memo(i + 1, j1 + dj1, j2 + dj2, grid, m, n, dp);
              maxi = max(maxi, ans);
            }
          }
         return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        // dp[m][n][n]
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return memo(0, 0, n - 1, grid, m, n, dp);
    }
};

























