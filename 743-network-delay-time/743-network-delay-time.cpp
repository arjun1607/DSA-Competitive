class Solution {
public:
    vector<int> dijkstra(vector<pair<int,int>> *adj, int n, int src){
        vector<int> vis(n+1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int wt = t.first;
            int vertex = t.second;
            if(vis[vertex]==-1){
                vis[vertex] = wt;
                for(auto i : adj[vertex]){
                    if(vis[i.first]==-1){
                        pq.push({i.second + wt, i.first});
                    }
                }
            }
        }
        return vis;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> t = dijkstra(adj, n, k);
        for(int i:t) cout<<i<<" ";
        int ans=0;
        for(int i=1;i<=n;i++){
            if(t[i]==-1) return -1;
            ans=max(ans, t[i]);
        }
        return ans;
    }
};