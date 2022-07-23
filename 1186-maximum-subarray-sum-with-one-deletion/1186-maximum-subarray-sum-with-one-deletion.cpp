class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        
        int n=arr.size();
        vector<int> dp1(n+1), dp2(n+1);
        
        int ans=arr[0];
        for(int i=0;i<n;i++){
            dp1[i+1]=(dp1[i]>=0)?dp1[i]+arr[i]:arr[i];
            ans=max(ans, dp1[i+1]);
        }
        for(int i=n-1;i>=0;i--){
            dp2[i]=(dp2[i+1]>=0)?dp2[i+1]+arr[i]:arr[i];
        }
        
        for(int i=1;i<=n;i++){
            ans=max(ans, dp1[i-1]+dp2[i]);
        }
        
        return ans;
        
    }
};