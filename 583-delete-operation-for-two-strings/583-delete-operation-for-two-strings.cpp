class Solution {
public:
    int memo(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i==0 && j==0) return 0;
        else if(i==0) return j;
        else if(j==0) return i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i-1]==t[j-1]) return dp[i][j]=memo(i-1, j-1, s, t, dp);
        else return dp[i][j]= 1 + min(memo(i-1, j, s, t, dp), memo(i, j-1, s, t ,dp));
    }
    int minDistance(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memo(n, m, s, t, dp);
    }
};
