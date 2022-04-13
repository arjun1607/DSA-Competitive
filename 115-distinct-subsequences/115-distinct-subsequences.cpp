class Solution {
public:
    int memo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s2[j-1]==s1[i-1])
            return dp[i][j]=memo(i-1, j-1, s1, s2, dp) + memo(i-1, j, s1, s2, dp);
        else 
            return dp[i][j]=memo(i-1, j, s1, s2, dp);
    }
    int numDistinct(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        /*
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memo(n, m, s1, s2, dp);
        */
        
        /*
        long dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else{
                    if(s2[j-1]==s1[i-1])
                        dp[i][j] = int(dp[i-1][j-1] + dp[i-1][j]); 
                    else 
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
        */
        
        /* 
        vector<long> prev(m+1), curr(m+1);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0) curr[j]=1;
                else if(i==0) curr[j]=0;
                else{
                    if(s2[j-1]==s1[i-1])
                        curr[j] = int(prev[j-1] + prev[j]); 
                    else 
                        curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return prev[m];
        */
        
        vector<long> prev(m+1, 0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                    if(s2[j-1]==s1[i-1])
                        prev[j] = int(prev[j-1] + prev[j]); 
                    else 
                        prev[j]=prev[j];
            }
        }
        return prev[m];
    }
};