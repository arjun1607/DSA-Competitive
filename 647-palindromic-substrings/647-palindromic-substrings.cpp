class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int ans=0;
        for(int i=0;i<n;i++) dp[i][i]=true, ans++;
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(s[i]==s[j]){
                    if(j==i+1 || dp[i+1][j-1]==true) {
                        dp[i][j]=true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};