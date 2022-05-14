class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1=nums[0], c1=1, val2=nums[0], c2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==val1) c1++;
            else if(nums[i]==val2) c2++;
            else if(nums[i]!=val1 && c1==0){
                val1=nums[i]; c1=1;
            }else if(nums[i]!=val2 && c2==0){
                val2=nums[i]; c2=1;
            }else{
                c1--; c2--;
            }
        }
        int f1=0, f2=0;
        for(int i:nums){
            if(i==val1) f1++;
            else if(i==val2) f2++;
        }
        vector<int> ans;
        if(f1>nums.size()/3) ans.push_back(val1);
        if(f2>nums.size()/3) ans.push_back(val2);
        return ans;
    }
};