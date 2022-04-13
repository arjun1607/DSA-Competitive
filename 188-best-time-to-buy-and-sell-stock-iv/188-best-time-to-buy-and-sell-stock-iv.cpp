class Solution {
public:
    int memo(int i, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp, int k){
        if(i==prices.size() || k==0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int profit;
        if(buy){
            profit=max(-prices[i] + memo(i+1, 0, prices, dp, k),
                          0 + memo(i+1, 1, prices, dp, k));
        }else {
            profit=max( prices[i] + memo(i+1, 1, prices, dp, k-1),
                          0 + memo(i+1, 0, prices, dp, k));
        }
        return dp[i][buy][k]=profit;
    }    
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return memo(0, 1, prices, dp, k);
    }
};