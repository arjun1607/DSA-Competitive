class Solution {
public:
    int memo(int i, int target, vector<int> &nums){
        if(i==0){
            if(nums[0]==target || -1*nums[0]==target){
                if(nums[0]==0) return 2;
                return 1;
            }
            return 0;
        }
        int plus = memo(i-1, target-nums[i], nums);
        int minus = memo(i-1, target+nums[i], nums);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return memo(n-1, target, nums);
    }
};