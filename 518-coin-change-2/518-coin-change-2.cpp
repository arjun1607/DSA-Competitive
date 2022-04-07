class Solution {
public:
    int memo(int i, int T, vector<int> &coins, vector<vector<int>> &dp){
        if(T==0) return 1;
        if(i==0){
            if(T%coins[i]==0) return 1;
            return 0;
        }
        
        if(dp[i][T]!=-1) return dp[i][T];
        
        int nottake = memo(i-1, T, coins, dp);
        int take = 0;
        if(coins[i] <= T) take = memo(i, T-coins[i], coins, dp);
        
        return dp[i][T]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        /*
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return memo(n-1, amount, coins, dp);
        */
        vector<vector<int>> dp(n, vector<int>(amount+1));
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0) dp[0][T]=1;
            else dp[0][T]=0;
        }
        for(int i=1;i<n;i++){
            for(int T=1;T<=amount;T++){
                int nottake = dp[i-1][T]; 
                int take = 0;
                if(coins[i] <= T) take = dp[i][T-coins[i]];
                dp[i][T]=take+nottake;
            }
        }
        return dp[n-1][amount];
    }
};



































