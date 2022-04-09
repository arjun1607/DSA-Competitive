class Solution {
public:
    /*
    int ans=0;
    void solve(int i, int j, vector<int> &nums1, vector<int> &nums2, int count){
        ans=max(ans, count);
        cout<<ans<<endl;
        if(i==nums1.size() || j==nums2.size()) return;
        if(nums1[i]==nums2[j]){
            solve(i+1, j+1, nums1, nums2, count+1);
        }
        solve(i+1, j, nums1, nums2, 0);
        solve(i, j+1, nums1, nums2, 0);
    }
    */
    
    /* count -> string s ko (i-1) tak and string t ko(j-1) tak ka longest common suffix
      we will just simply take each possible pair (i, j) and try to extend it from there to get maximum common suffix ending at that index pair-1. Finally, we will return the max length found after trying out all pairs
    */
    
    /*
    int lcs(int i, int j, vector<int> &nums1, vector<int> &nums2, int count, 
                          vector<vector<vector<int>>> &dp){
        if(i==nums1.size() || j==nums2.size()) return count;
        if(dp[i][j][count]!=-1) return dp[i][j][count];
        int abtak_ka_maxsuffix=count;
        if(nums1[i]==nums2[j]){
            abtak_ka_maxsuffix=lcs(i+1, j+1, nums1, nums2, count+1, dp);
        }
        int opt2 = lcs(i+1, j, nums1, nums2, 0, dp);
        int opt3 = lcs(i, j+1, nums1, nums2, 0, dp);
        return dp[i][j][count]=max({abtak_ka_maxsuffix, opt2, opt3});
    }
    */
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /* RECURSION       
          solve(0,0,nums1,nums2,0);
          return ans;
        */
        
        /* MEMOIZATION
        
        int n=nums1.size(), m=nums2.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(min(n,m)+1, -1)));
        return lcs(0,0,nums1,nums2,0,dp);
        */
        
        int n=nums1.size(), m=nums2.size();
        // TABULATION
        vector<vector<int>>  dp(n+1, vector<int>(m+1, 0));
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res=max(res, dp[i][j]);
                }else dp[i][j]=0;
            }
        }
        return res;
    }
};


















