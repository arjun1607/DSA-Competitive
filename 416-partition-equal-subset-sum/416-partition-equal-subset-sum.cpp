class Solution {
public:
    bool memo(int i, int k, vector<int> &arr, vector<vector<int>> &dp){
        if(k==0) return true;
        if(i==0) return arr[0]==k;
        if(dp[i][k]!=-1) return dp[i][k];
        bool nottake=memo(i-1, k, arr, dp);
        bool take=false;
        if(arr[i]<=k) take=memo(i-1, k-arr[i], arr, dp);
        return dp[i][k]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum%2==1) return false; 
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, -1));
        return memo(nums.size()-1, sum/2, nums, dp);
    }
};