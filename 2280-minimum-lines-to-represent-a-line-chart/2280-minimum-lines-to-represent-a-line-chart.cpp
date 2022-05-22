class Solution {
public:
    int minimumLines(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        if(arr.size()==1) return 0;
        long double y=arr[1][1]-arr[0][1];
        long double x=arr[1][0]-arr[0][0];
        int ans=1;
        for(int i=2;i<arr.size();i++){
             long double yy=arr[i][1]-arr[i-1][1];
             long double xx=arr[i][0]-arr[i-1][0];
             if(yy*1.0/xx != y*1.0/x)  ans++;
             y=yy;
             x=xx;
        }
        return ans;
    }
};