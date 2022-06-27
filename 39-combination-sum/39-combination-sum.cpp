class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &arr, int sum, int k, vector<int> &temp){
        if(i==arr.size()){
            if(sum==k) ans.push_back(temp);
            return;
        }
        
        solve(i+1, arr, sum, k, temp);
        
        if(sum + arr[i] <= k){
            temp.push_back(arr[i]);
            solve(i, arr, sum+arr[i], k, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<int> temp;
        solve(0, arr, 0, k, temp);
        return ans;
    }
};