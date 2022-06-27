class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, int remainingSum, int ssf, int ts, vector<int> &temp){
        if(i==10){
            if(remainingSum==0 && ssf==ts) ans.push_back(temp);
            return;
        }
        
        solve(i+1, remainingSum, ssf, ts, temp);
        
        if(i<=remainingSum){
            temp.push_back(i);
            solve(i+1, remainingSum-i, ssf+1, ts, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(1, n, 0, k, temp);
        return ans;
    }
};