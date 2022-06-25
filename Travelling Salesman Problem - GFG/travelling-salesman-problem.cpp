// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int dp[11][1<<11];
    int solve(int i, int mask, vector<vector<int>> &cost, int n){
        if(mask==0){
            return cost[i][0];
        }
        
        if(dp[i][mask]!=-1) return dp[i][mask];
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                ans=min(ans, cost[i][j] + solve(j, mask^(1<<j), cost, n));
            }
        }
        return dp[i][mask]=ans;
    }
    int total_cost(vector<vector<int>>cost){
        int n=cost.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, (1<<n)-2, cost, n);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends