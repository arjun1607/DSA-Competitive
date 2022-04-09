class Solution {
public:
    int memo(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i==0 && j==0) return 0;
        else if(i==0){
            int ans=0;
            while(j>=1){
                ans+=int(t[j-1]);
                j--;
            }
            return ans;
        }
        else if(j==0){
            int ans=0;
            while(i>=1){
                ans+=int(s[i-1]);
                i--;
            }
            return ans;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i-1]==t[j-1])
            return dp[i][j]=memo(i-1, j-1, s, t, dp);
        else 
            return dp[i][j]=min( int(s[i-1])+memo(i-1, j, s, t, dp), int(t[j-1]) +memo(i, j-1, s, t, dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memo(n, m, s1, s2, dp);
    }
};