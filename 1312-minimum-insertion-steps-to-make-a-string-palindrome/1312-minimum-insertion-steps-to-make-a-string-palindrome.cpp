class Solution {
public:
    int memo(int i, int j, string &s, vector<vector<int>> &dp){
        if(j<=i) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        // if same no need to delete
        // else either delete ith char or jth char
        if(s[i]==s[j]) return dp[i][j]=memo(i+1, j-1, s, dp);
        else return dp[i][j]=1+min(memo(i+1,j,s,dp), memo(i,j-1,s,dp));
            
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memo(0, n-1, s, dp);
    }
};