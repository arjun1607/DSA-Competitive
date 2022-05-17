class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int presentMax=nums[0], nextMax=nums[0], pidx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<presentMax){
                pidx=i;
                presentMax=nextMax;
            }
            nextMax=max(nextMax, nums[i]);            
        }
        return pidx+1;
    }
};