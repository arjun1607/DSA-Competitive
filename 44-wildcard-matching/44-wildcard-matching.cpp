class Solution {
public:
    bool memo(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==0 && j==0) return true;
        if(j==0 && i>=1) return false;
        if(i==0 && j>=1){
            for(int jj=1;jj<=j;jj++)if(p[jj-1]!='*') return false;
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j] = memo(i-1, j-1, s, p, dp);
        }
        else if(p[j-1]=='*'){
            return dp[i][j] = memo(i, j-1, s, p, dp) || memo(i-1, j, s, p, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //return memo(n, m, s, p, dp);
        bool dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0) dp[i][j]=true;
                else if(j==0) dp[i][j]=false;
                else if(i==0){
                    dp[i][j]=true;
                    for(int jj=1;jj<=j;jj++){
                        if(p[jj-1]!='*') dp[i][j]=false;
                    }
                }
                else{
                    if(s[i-1]==p[j-1] || p[j-1]=='?')
                        dp[i][j] = dp[i-1][j-1];                 
                    else if(p[j-1]=='*')                    
                        dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    else  
                        dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
    
};