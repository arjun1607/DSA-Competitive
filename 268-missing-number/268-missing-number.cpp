class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(int val:nums) ans^=val;
        for(int i=0;i<=nums.size();i++) ans^=i;
        return ans;
    }
};