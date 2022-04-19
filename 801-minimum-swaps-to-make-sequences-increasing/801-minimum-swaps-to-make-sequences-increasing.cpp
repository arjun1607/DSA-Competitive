class Solution {
public:
    int memo(int i, vector<int>& nums1, vector<int>& nums2, bool swapped, vector<vector<int>> &dp){
        if(i==nums1.size()) return 0;
        
        if(dp[i][swapped]!=-1) return dp[i][swapped];
        
        int ans=1e8;
        
        if(nums1[i]<=nums1[i-1] || nums2[i]<=nums2[i-1]){        
            swap(nums1[i], nums2[i]);
            ans=memo(i+1,nums1,nums2, 1, dp)+1;
            swap(nums1[i], nums2[i]);
        }
        else if(nums1[i-1]>=nums2[i] || nums2[i-1]>=nums1[i]){
            ans=memo(i+1,nums1,nums2, 0, dp);
        }
        else{         
            swap(nums1[i], nums2[i]);
            ans=1+memo(i+1,nums1,nums2, 1, dp);
            swap(nums1[i], nums2[i]);
            
            ans=min(ans, memo(i+1,nums1,nums2, 0, dp));
        }
        
        return dp[i][swapped]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);             
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return memo(1, nums1, nums2, 0, dp);
    }
};