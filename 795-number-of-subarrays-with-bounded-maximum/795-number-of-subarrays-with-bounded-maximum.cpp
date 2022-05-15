class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int l, int r) {
        int prevvalidcount=0, ans=0;
        for(int i=0, j=0;j<nums.size(); j++){
            if(nums[j]>r){
                prevvalidcount=0;
                i=j+1;
            }else if(nums[j]<l){
                ans+=prevvalidcount;
            }else{
                // in range
                ans+=(j-i+1);
                prevvalidcount=(j-i+1);
            }
        }
        return ans;
    }
};