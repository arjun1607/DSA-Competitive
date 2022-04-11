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
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memo(n, m, s, p, dp);
    }
};