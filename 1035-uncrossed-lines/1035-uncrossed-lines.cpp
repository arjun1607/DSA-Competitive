class Solution {
public:
    int memo(int i, int j, vector<int> &s, vector<int> &t, vector<vector<int>> &dp){
        if(i==0||j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1])
            return dp[i][j]=1+memo(i-1, j-1, s, t, dp);
        else 
            return dp[i][j]=max(memo(i-1, j, s, t, dp), memo(i, j-1, s, t, dp));
    } 
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memo(n, m, nums1, nums2, dp);
    }
};