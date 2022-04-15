class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        int len=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=i-1;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                    len=max(len, dp[i]);
                }
            }
        }
        // 1 4 7 8 16
        vector<int> ans;
        int k=len;
        for(int i=nums.size()-1; i>=0; i--){
            if(dp[i]==len && k==len){
                ans.push_back(nums[i]);
                k--;
            }
            else if(dp[i]==k && ans.back()%nums[i]==0){
                ans.push_back(nums[i]);
                k--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};