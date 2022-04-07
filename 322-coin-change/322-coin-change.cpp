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
        /*
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int ans=memo(n-1, target, coins, dp);
        return (ans>=1e9)?-1:ans;
        */
        
        /* TABULATION
        vector<vector<int>> dp(n, vector<int>(target+1));
        for(int T=0;T<=target;T++){
            if(T%coins[0] == 0) dp[0][T]=T/coins[0];
            else dp[0][T]=1e9;
        }
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int i=1;i<n;i++){
            for(int T=1;T<=target;T++){
                int nottake = 0 + dp[i-1][T];
                int take =INT_MAX;
                if(coins[i]<=T) take = 1 + dp[i][T-coins[i]];
                dp[i][T] = min(take, nottake);
            }
        }
        return (dp[n-1][target]>=1e9)?-1:dp[n-1][target];
        */
        
        // SPACE OPTIMISED
        vector<int> prev(target+1), curr(target+1);
        for(int T=0;T<=target;T++){
            if(T%coins[0] == 0) prev[T]=T/coins[0];
            else prev[T]=1e9;
        }
        prev[0]=0;
        for(int i=1;i<n;i++){
            curr[0]=0;
            for(int T=1;T<=target;T++){
                int nottake = 0 + prev[T];
                int take =INT_MAX;
                if(coins[i]<=T) take = 1 + curr[T-coins[i]];
                curr[T] = min(take, nottake);
            }
            prev=curr;
        }
        return (prev[target]>=1e9)?-1:prev[target];
    }
};



















