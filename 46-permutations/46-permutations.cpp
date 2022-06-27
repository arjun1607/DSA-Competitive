class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int idx, vector<int> &temp){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<temp.size();i++){
            if(temp[i]==INT_MIN){
                temp[i]=nums[idx];
                solve(nums, idx+1, temp);
                temp[i]=INT_MIN;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n, INT_MIN);
        solve(nums, 0, temp);
        return ans;
    }
};