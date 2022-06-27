class Solution {
public:
    vector<vector<int>> ans;
    void solve(int currnoidx, vector<int> &temp, vector<int> &nums, unordered_map<int,int> &lastoccur){
        if(currnoidx==temp.size()){
            ans.push_back(temp);
            return;
        }
  
        int val=nums[currnoidx];
        int lo = lastoccur[val];
  
        for(int i=lo+1; i<temp.size();i++){
            if(temp[i]==INT_MIN){
                lastoccur[val]=i;
                temp[i]=val;
                solve(currnoidx+1, temp, nums, lastoccur);
                lastoccur[val]=lo;
                temp[i]=INT_MIN;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> lastoccur;
        for(int i:nums) lastoccur[i]=-1;
        int n=nums.size();
        vector<int> temp(n, INT_MIN);
        solve(0, temp, nums, lastoccur);
        return ans;
    }
};