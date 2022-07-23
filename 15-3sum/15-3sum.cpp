class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       // vector<vector<int>> ans;
        unordered_set<int> s;
        set<vector<int>> unique;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1; j<n;j++){
                if(s.find(-(nums[i]+nums[j])) != s.end()){
                    vector<int> v={nums[i], nums[j], -(nums[i]+nums[j])};
                    sort(v.begin(), v.end());
                   //  if(unique.find(v)==unique.end()) ans.push_back(v);
                    unique.insert(v);
                }
            }
            s.insert(nums[i]);
        }
        vector<vector<int>> ans(unique.begin(), unique.end());
        return ans;
    }
};