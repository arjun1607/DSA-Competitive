class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            int ans=1;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    ans=max(ans, dp[j]+1);
                }
            }
            dp[i]=ans;
        }
        return *max_element(dp.begin(), dp.end());
    }
};