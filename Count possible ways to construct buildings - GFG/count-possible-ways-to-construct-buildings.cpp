// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	   long long last0=1, last1=1, tot=2, MOD = 1e9 + 7;
	   for(int i=1;i<n;i++){
	       last1=last0%MOD;
	       last0=tot%MOD;
	       tot=(last1%MOD+last0%MOD)%MOD;
	   }
	   tot=tot%MOD;
	   tot=(tot*tot)%MOD;
	   return tot;
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