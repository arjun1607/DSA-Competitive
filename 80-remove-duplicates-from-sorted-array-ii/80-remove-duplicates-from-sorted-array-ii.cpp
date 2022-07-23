class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int idx=2, i=2;
        while(i<n){
            if(nums[i]!=nums[idx-2]){
                nums[idx]=nums[i];
                i++;
                idx++;
            }
            else i++;
        }
        return idx;
    }
};