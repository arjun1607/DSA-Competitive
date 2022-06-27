class Solution {
public:
    vector<vector<int>> ans;
    void solve(int currbox, int totbox, int ssf, int ts, vector<int> &temp){
        if(currbox > totbox){
            if(ssf == ts){
                ans.push_back(temp);
            }
            return;
        }
        
        solve(currbox+1, totbox, ssf, ts, temp);
        
        temp.push_back(currbox);
        solve(currbox+1, totbox, ssf+1, ts, temp);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, n, 0, k, temp);
        return ans;
    }
};