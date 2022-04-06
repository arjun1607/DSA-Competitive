// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	   int totsum=0;
	   for(int i=0;i<n;i++) totsum+=arr[i];
	   vector<vector<bool>> dp(n, vector<bool>(totsum+1, false));
	   for(int i=0;i<n;i++) dp[i][0]=true;
	   dp[0][arr[0]]=true;
	   for(int i=1;i<n;i++){
	       for(int j=1;j<=totsum;j++){
	           int nottaken=dp[i-1][j];
	           int taken=false;
	           if(arr[i]<=j) taken=dp[i-1][j-arr[i]];
	           dp[i][j]=taken||nottaken;
	       }
	   }
	   int ans=INT_MAX;
	   for(int s1=0;s1<=totsum/2;s1++){
	       if(dp[n-1][s1]==true) ans=min(ans, abs(totsum-2*s1));
	   }
	   return ans;
	}

};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends