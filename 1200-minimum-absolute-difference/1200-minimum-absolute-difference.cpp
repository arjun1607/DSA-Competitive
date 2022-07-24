class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, set<vector<int>>> m;
        int mini=INT_MAX;
        for(int i=1;i<arr.size();i++){
            mini=min(mini, arr[i]-arr[i-1]);
            m[arr[i]-arr[i-1]].insert({arr[i-1], arr[i]});
        }
        vector<vector<int>> ans(m[mini].begin(), m[mini].end());
        return ans;
    }
};