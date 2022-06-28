class Solution {
public:
    
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &unique, unordered_map<int, int> &fmap, vector<int> &temp, int target){
        if(idx==unique.size() || target==0){
            if(target==0) ans.push_back(temp);
            return;
        } 
        
        int val=unique[idx];
        for(int i=1; i<= fmap[val]; i++){
            for(int j=0;j<i;j++) {
                temp.push_back(val);
                target-=val;
            }
            if(target>=0) solve(idx+1, unique, fmap, temp, target);
            for(int j=0;j<i;j++) {
                temp.pop_back();
                target+=val;
            }
        }
        
        solve(idx+1, unique, fmap, temp, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {                                                 unordered_map<int, int> fmap;
        vector<int> unique;
        for(int i:nums){
            if(fmap.find(i)==fmap.end()){
                unique.push_back(i);
            }
            fmap[i]++;
        }
        
        vector<int> temp;
        solve(0, unique, fmap, temp, target);
        return ans;
    }
};