class Solution {
public:
    int memo(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i==0||j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1])
            return dp[i][j]=1+memo(i-1, j-1, s, t, dp);
        else 
            return dp[i][j]=max(memo(i-1, j, s, t, dp), memo(i, j-1, s, t, dp));
    }
    int longestCommonSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
        /* MEMOIZATION
           vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
           return memo(n, m, s, t, dp);
        */
        
        /* TABUALR
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else{              
                    if(s[i-1]==t[j-1])
                       dp[i][j]= 1+dp[i-1][j-1];
                    else
                       dp[i][j]=max(dp[i-1][j],dp[i][j-1]);            
                }
            }
        }
        return dp[n][m];
        */
        
        // SPACE OPTIMISED
        vector<int> prev(m+1), curr(m+1);
        for(int j=0;j<=m;j++) prev[j]=0;
        for(int i=1;i<=n;i++){
            curr[0]=0;
            for(int j=1;j<=m;j++){              
                if(s[i-1]==t[j-1])
                    curr[j]= 1+prev[j-1];
                else
                    curr[j]=max(prev[j], curr[j-1]);            
            }
            prev=curr;
        }
        return curr[m];
        
    }
};