// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int> *adj, vector<bool> &vis, int src, stack<int> &s){
	    vis[src]=true;
	    for(int i:adj[src]){
	        if(!vis[i]){
	            dfs(adj, vis, i, s);
	        }
	    }
	    s.push(src);
	}
	void dfs(vector<int> *graph, vector<bool> &vis, int src){
	    vis[src]=true;
	    for(int i:graph[src]){
	        if(!vis[i]){
	            dfs(graph, vis, i);
	        }
	    }
	}
    int kosaraju(int v, vector<int> adj[]){
        stack<int> s;
        vector<bool> vis(v, false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(adj, vis, i, s);
            }
        }
        vector<int> graph[v];
        for(int i=0;i<v;i++){
            for(int j:adj[i]){
                graph[j].push_back(i);
            }
        }
        
        vector<bool> vis2(v, false);
        int count=0;
        while(!s.empty()){
            int i=s.top();
            if(!vis2[i]){
                dfs(graph, vis2, i);
                count++;
            }
            s.pop();
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends