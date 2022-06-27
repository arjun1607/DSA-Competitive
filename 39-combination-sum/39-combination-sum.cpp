class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &arr, int k, vector<int> &temp){
        if(i==arr.size()){
            if(k==0) ans.push_back(temp);
            return;
        }
        
        solve(i+1, arr, k, temp);
        
        if(arr[i] <= k){
            temp.push_back(arr[i]);
            solve(i, arr, k-arr[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<int> temp;
        solve(0, arr, k, temp);
        return ans;
    }
};