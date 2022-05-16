// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    string getSmallest(long long n) {
        if(n==1) return "1";
        string ans="";
        int i=9;
        while(i>1 && n!=1){
            if(n%i==0){
                char c='0'+i;
                ans=c+ans;
                n=n/i;
            }else i--;
        }
        return (n==1 && i>=1)?ans:"-1";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.getSmallest(N) << endl;
    }
    return 0;
}  // } Driver Code Ends