class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0;
        for(int &i:nums) if(i==val) { i=INT_MAX; c++; }
        sort(nums.begin(), nums.end());
        return nums.size()-c;
    }
};