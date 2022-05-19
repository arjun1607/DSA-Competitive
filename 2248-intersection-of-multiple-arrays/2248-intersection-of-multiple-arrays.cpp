class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> arr(1001, 0);
        for(auto &i:nums){
            for(int &j:i) arr[j]++;
        }
        vector<int> ans;
        for(int i=0;i<=1000;i++) if(arr[i]==nums.size()) ans.push_back(i);
        return ans;
    }
};