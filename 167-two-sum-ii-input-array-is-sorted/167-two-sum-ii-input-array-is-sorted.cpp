class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        vector<int> ans;
        while(i<j){
            if(nums[i]+nums[j] > target) j--;
            else if(nums[i]+nums[j] < target) i++;
            else {
                ans.push_back(i+1);
                 ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};