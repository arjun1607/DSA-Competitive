class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        multiset<int> m; for(int i:nums) m.insert(i);
        vector<int> ans;
        for(int i:nums){
            ans.push_back(distance(m.begin(),m.lower_bound(i)));
        }
        return ans;
    }
};