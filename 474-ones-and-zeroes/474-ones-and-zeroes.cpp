class Solution {
public:
    int memo(int i, int p, int q, vector<string> &arr, vector<vector<vector<int>>> &dp){
        int c0=0, c1=0;
        for(char &c:arr[i])
            if(c=='0') c0++; else c1++;
        
        if(i==0){
            if(c0<=p && c1<=q) return 1;
            else return 0;
        }
        
        if(dp[i][p][q]!=-1) return dp[i][p][q];
        
        int nottake=memo(i-1, p, q, arr, dp);
        int take=0;
        if(c0<=p && c1<=q) take=1+memo(i-1, p-c0, q-c1, arr, dp);
        
        return dp[i][p][q]=max(take, nottake);
    }
    int findMaxForm(vector<string>& arr, int p, int q) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(p+1, vector<int>(q+1, -1)));
        return memo(n-1, p, q, arr, dp);
    }
};