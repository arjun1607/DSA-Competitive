// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int memo(int i, int w, int price[], vector<vector<int>> &dp){
        int rodlen=i+1;
        if(i==0){
           return ((int)(w/rodlen))*price[i];
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int nottake = 0 + memo(i-1, w, price, dp);
        int take=0;
        if(rodlen <= w) take=price[i]+memo(i, w-rodlen, price, dp);
        return dp[i][w]=max(take, nottake);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return memo(n-1, n, price, dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends