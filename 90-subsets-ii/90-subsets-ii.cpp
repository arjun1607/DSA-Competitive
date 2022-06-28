class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &unique, unordered_map<int, int> &fmap, vector<int> &temp){
        if(idx==unique.size()){
            ans.push_back(temp);
            return;
        }
        
        int val=unique[idx];
        for(int i=1; i<= fmap[val]; i++){
            for(int j=0;j<i;j++) temp.push_back(val);
            solve(idx+1, unique, fmap, temp);
            for(int j=0;j<i;j++) temp.pop_back();
        }
        
        solve(idx+1, unique, fmap, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> fmap;
        vector<int> unique;
        for(int i:nums){
            if(fmap.find(i)==fmap.end()){
                unique.push_back(i);
            }
            fmap[i]++;
        }
        
        vector<int> temp;
        solve(0, unique, fmap, temp);
        return ans;
    }
};