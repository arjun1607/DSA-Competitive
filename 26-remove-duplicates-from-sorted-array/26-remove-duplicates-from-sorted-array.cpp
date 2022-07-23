class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int i=0, j=1;
        while(j<nums.size()){
            if(nums[j]==nums[i]) j++;
            else{
                nums[i+1]=nums[j];
                i++; j++;
            }
        }
        return i+1;
    }
};