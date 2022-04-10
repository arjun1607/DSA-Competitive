class Solution {
public:
    int memo(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(i==0 || j==0) return max(i,j);
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j]=memo(i-1, j-1, s, t, dp);
        else return dp[i][j]=1+min({memo(i, j-1, s, t, dp), 
                     memo(i-1, j-1, s, t, dp), memo(i-1, j, s, t, dp)});
    }
    int minDistance(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memo(n, m, s, t, dp);
    }
};