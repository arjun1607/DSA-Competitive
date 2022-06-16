class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int len=1;
        string ans(1, s[0]);
        for(int i=0;i<n;i++) dp[i][i]=true;
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(s[i]==s[j]){
                    if(j==i+1 || dp[i+1][j-1]==true) {
                        dp[i][j]=true;
                        if(j-i+1 > len){
                            len=j-i+1;
                            ans = s.substr(i, j-i+1);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};