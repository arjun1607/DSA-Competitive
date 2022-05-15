class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++) pre[i]=pre[i-1]*nums[i];
        int k=1;
        vector<int> ans(nums.size());
        for(int j=nums.size()-1;j>=1;j--){
            ans[j]=k*pre[j-1];
            k*=nums[j];
        }
        ans[0]=k;
        return ans;
    }
};