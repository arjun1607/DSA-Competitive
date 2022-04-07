class Solution {
public:
    int memo(int i, int T, vector<int> &coins, vector<vector<int>> &dp){
        if(T==0) return 0;
        if(i==0){
            if(T%coins[0] == 0) return T/coins[0];
            return 1e9;
        }
        
        if(dp[i][T]!=-1) return dp[i][T];
        
        int nottake = 0 + memo(i-1, T, coins, dp);
        int take =INT_MAX;
        if(coins[i]<=T) take = 1 + memo(i, T-coins[i], coins, dp);
        
        return dp[i][T] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int ans=memo(n-1, target, coins, dp);
        return (ans>=1e9)?-1:ans;
    }
};