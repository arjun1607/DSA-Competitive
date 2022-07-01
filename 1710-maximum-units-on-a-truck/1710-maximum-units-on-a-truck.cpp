class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int k) {
        sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0] <= k){
                ans += (arr[i][0] * arr[i][1]);
                k-=arr[i][0];
            }else{
                ans += (k*arr[i][1]);
                k=0;
            }
        }
        return ans;
    }
};