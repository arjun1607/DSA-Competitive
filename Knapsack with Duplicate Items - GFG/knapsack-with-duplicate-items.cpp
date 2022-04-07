// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int memo(int i, int w, int val[], int wt[], vector<vector<int>> &dp){
        if(i==0){
            return ((int)(w/wt[0]))*val[0];
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int nottake= 0 + memo(i-1, w, val, wt, dp);
        int take=0;
        if(wt[i]<=w) take=val[i]+memo(i, w-wt[i], val, wt, dp);
        return dp[i][w]=max(take, nottake);
    }
    int knapSack(int n, int w, int val[], int wt[]){
        // vector<vector<int>> dp(n, vector<int>(w+1, -1));
        // return memo(n-1, w, val, wt, dp);
        
        /*
        vector<vector<int>> dp(n, vector<int>(w+1));
        for(int j=0;j<=w;j++){
            dp[0][j]=((int)(j/wt[0]))*val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(wt[i]<=j) take=val[i]+dp[i][j-wt[i]];
                dp[i][j]=max(take, nottake);
            }
        }
        return dp[n-1][w];
        */
        
        vector<int> prev(w+1), curr(w+1);
        for(int j=0;j<=w;j++){
            prev[j]=((int)(j/wt[0]))*val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int nottake=prev[j];
                int take=0;
                if(wt[i]<=j) take=val[i]+curr[j-wt[i]];
                curr[j]=max(take, nottake);
            }
            prev=curr;
        }
        return prev[w];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends