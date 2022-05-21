class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int s=arr[0][0], e=arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(arr[i][0] > e) {
                ans.push_back({s,e});
                s=arr[i][0];
                e=arr[i][1];
            }
            else e=max(e, arr[i][1]);
        }
        ans.push_back({s,e});
        return ans;
    }
};