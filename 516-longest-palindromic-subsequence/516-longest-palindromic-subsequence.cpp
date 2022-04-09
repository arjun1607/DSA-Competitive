class Solution {
public:
    int memo(int i, int j, string &s, vector<vector<int>> &dp){
        if(j<i) return 0;
        if(j==i) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        // if same -> both are part of lps
        // if different only one can be part of lps
        if(s[i]==s[j]) return dp[i][j]=2+memo(i+1, j-1, s, dp);
        else return  dp[i][j] = max(memo(i+1, j, s, dp), memo(i, j-1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        /*
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return memo(0, n-1, s, dp);
        */
        
        // TABULATION -> from BOTTOM to UP -> from BASE CASE to memo call
        int dp[n][n];
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j<i) dp[i][j]=0;
                else if(j==i) dp[i][j]=1;
                else{
                // if same -> both are part of lps
                // if different only one can be part of lps
                  if(s[i]==s[j])  dp[i][j]=2+dp[i+1][j-1]; 
                  else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};