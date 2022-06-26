int mod = 1e9+7;
class Solution {
public:
    long solve(int i, vector<long> &dp){
        if(i<0) return 1;
        
        if(dp[i]!=-1) return dp[i]%mod;
        
        long notplace = solve(i-1, dp);
        long place = solve(i-2, dp);
        
        return dp[i] =(place + notplace)%mod;
    }
    int countHousePlacements(int n) {
        vector<long> dp(n, -1);
        long ans = solve(n-1, dp)%mod;
        return (ans*ans)%mod;
    }
    
};