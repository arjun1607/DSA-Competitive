// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s, string t, int n, int m){
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=0;
                while((i+k)<s.size() && (j+k)<t.size() 
                          && s[i+k]==t[j+k]){
                    k++;
                }
                ans=max(ans, k);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends