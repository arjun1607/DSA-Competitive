class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=nums[0], c=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==val) c++;
            else{
                if(c==0){
                    val=nums[i];
                    c=1;
                }else c--;
            }
        }
        return val;
    }
};