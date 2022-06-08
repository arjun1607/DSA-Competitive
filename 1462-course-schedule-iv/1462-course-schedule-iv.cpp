class Solution {
public:
    void bfs(vector<int> *adj, int n, int src, vector<vector<bool>> &reachable){
        vector<bool> vis(n, false);
        vis[src]=true;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i:adj[node]){
                if(!vis[i]){
                    reachable[src][i]=true;
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& q) {
        vector<int> adj[n];
        for(auto i:prereq){
            adj[i[0]].push_back(i[1]);
        }
        vector<vector<bool>> reachable(n, vector<bool>(n, false));
        for(int i=0;i<n;i++){
            bfs(adj, n, i, reachable);
        }
        vector<bool> ans;
        for(auto i:q){
            int u=i[0], v=i[1];
            ans.push_back(reachable[u][v]);
        }
        return ans;
    }
};