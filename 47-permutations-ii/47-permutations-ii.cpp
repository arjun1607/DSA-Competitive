class Solution {
public:
    vector<vector<int>> ans;
    void solve(int currbox, vector<int> &temp, int totbox, unordered_map<int,int> &freq){
        if(currbox==totbox){
            ans.push_back(temp);
        }
        
        for(auto &it:freq){
            int val=it.first;
            if(it.second > 0){
                it.second--;
                temp.push_back(val);
                solve(currbox+1, temp, totbox, freq);
                temp.pop_back();
                it.second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i:nums) freq[i]++;
        
        int n=nums.size();
        vector<int> temp;
        solve(0, temp, n, freq);
        return ans;
    }
};