class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s; for(int i:nums) s.insert(i);
        nums.clear(); for(int i:s) nums.push_back(i);
        reverse(nums.begin(), nums.end());
        return (2>=nums.size())?nums[0]:nums[2];
    }
};