class Solution {
public:
    int memo(int i, int target, vector<int> &nums, vector<unordered_map<int,int>> &dp){
        if(i==0){
            if(nums[0]==target || -1*nums[0]==target){
                if(nums[0]==0) return 2;
                return 1;
            }
            return 0;
        }
        
        if(dp[i].find(target)!=dp[i].end()) return dp[i][target];
        
        // take the element at ith idx with + sign, so the target we are left with is 'target' - nums[i]
        int plus = memo(i-1, target-nums[i], nums, dp);
        // similarly when we take with - sign
        int minus = memo(i-1, target+nums[i], nums, dp);
        
        return dp[i][target] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n);
        return memo(n-1, target, nums, dp);
    }
};