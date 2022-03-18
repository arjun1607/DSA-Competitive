// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	    int dp[n][2] ; 
	    dp[0][0] = 1 ;
	    dp[0][1] = 1 ; 
	    int md = 1e9+7 ;
	    
	    for(int i=1;i<n;i++){
	        dp[i][0]= ( dp[i-1][0]+dp[i-1][1] )%md;
	        dp[i][1] = dp[i-1][0]%md ; 
	    }
	    
	    long long ans = dp[n-1][0]+dp[n-1][1] ; 
	    ans%=md ; 
	    ans = (ans*ans)%md ; 
	    return ans ;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends