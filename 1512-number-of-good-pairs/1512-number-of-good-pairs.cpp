class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            ans+=m[nums[i]];
            m[nums[i]]++;
        }
        return ans;
    }
};