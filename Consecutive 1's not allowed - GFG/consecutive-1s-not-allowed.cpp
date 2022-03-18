// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	   ll last0=1, last1=1, tot=2;
	   const ll MOD = 1e9 + 7;
	   for(int i=1;i<n;i++){
	       last1=last0%MOD;
	       last0=tot%MOD;
	       tot=(last1%MOD+last0%MOD)%MOD;
	   }
	   return tot%MOD;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends