class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]>nums[s.top()]){
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};