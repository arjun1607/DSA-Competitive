class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /* vector<int> dp(nums.size());
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
        */
        // USING BINARY SEARCH
        vector<int> dp(nums.size(), INT_MAX);
        int ans=0;
        for(int val:nums){
            int i=0, j=ans;
            int pos=-1;
            while(i<=j){
                int mid=i+(j-i)/2;
                if(dp[mid]==val) {
                    pos=mid; break;
                }else if(dp[mid]>val){
                    pos=mid; j=mid-1;
                }else i=mid+1;
            }
            dp[pos]=val;
            if(pos==ans) ans++;
        }
        return ans;
    }
};