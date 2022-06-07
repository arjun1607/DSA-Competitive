// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> ans(n, INT_MAX);
	    ans[0]=0;
	    for(int i=1;i<=n;i++){
	        for(auto it:edges){
	            int u=it[0], v=it[1], wt=it[2];
	            if(ans[u]==INT_MAX) continue;
	            if(ans[u]+wt < ans[v]){
	                ans[v]=ans[u]+wt;
	                if(i==n) return 1;
	            }
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends