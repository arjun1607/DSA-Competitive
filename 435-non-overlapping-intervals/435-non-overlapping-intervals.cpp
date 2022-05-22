class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int s=arr[0][0], e=arr[0][1];
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<e && arr[i][1]>e) ans++;
            else if(arr[i][0]>=s && arr[i][1]<=e){
                ans++;
                s=arr[i][0];
                e=arr[i][1];
            }else{
                s=arr[i][0];
                e=arr[i][1];
            }
        }
        return ans;
    }
};