// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int> *adj, vector<bool> &vis, int src, stack<int> &s){
        vis[src]=true;
        for(int i:adj[src]){
            if(!vis[i]) dfs(adj, vis, i, s);
        }
        s.push(src);
    }
    void dfs(vector<int> *adj, vector<bool> &vis, int src){
        vis[src]=true;
        for(int i:adj[src]){
            if(!vis[i]) dfs(adj, vis, i);
        }
    }
	int findMotherVertex(int v, vector<int>adj[]){
	    stack<int> s;
	    vector<bool> vis(v, false);
	    for(int i=0;i<v;i++){
	        if(!vis[i]) dfs(adj, vis, i, s);
	    }
	    int possible_ans=s.top();
	    vector<bool> vis2(v, false);
	    dfs(adj, vis2, possible_ans);
	    for(bool i:vis2){
	        if(i==false) return -1;
	    }
	    return possible_ans;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends