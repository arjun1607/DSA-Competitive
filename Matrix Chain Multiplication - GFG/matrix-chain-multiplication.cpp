// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int memo(int i, int j, int arr[], vector<vector<int>> &dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int k=i; k<=j-1; k++){
            int steps=arr[i-1]*arr[k]*arr[j] + memo(i,k,arr,dp) + memo(k+1,j,arr,dp);
            mini=min(steps, mini);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int n, int arr[]){
        /*
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memo(1, n-1, arr, dp);
        */
        int dp[n][n];
        for(int i=1;i<n;i++) dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n-1;j++){
                    int mini = 1e9;
                    for(int k=i; k<=j-1; k++){
                        int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];
                        mini=min(steps, mini);
                    }
                    dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends