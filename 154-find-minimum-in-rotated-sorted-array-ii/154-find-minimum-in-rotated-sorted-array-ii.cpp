class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0, e=n-1, ans=nums[0];
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]>nums[e]){
                s=m+1;
            }
            else if(nums[m]<nums[e]){
                ans=min(ans, nums[m]);
                e=m-1;
            }
            else {
                ans=min(ans, nums[m]);
                e--;
            }
        }
        return ans;
    }
};