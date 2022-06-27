class Solution {
public:
    int memo(vector<int> &nums, int target, vector<int> &dp){
        if(target==0) return 1;
        if(target<0) return 0;
        
        if(dp[target]!=-1) return dp[target];
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= target)
                ans += memo(nums, target-nums[i], dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return memo(nums, target, dp);
    }
};