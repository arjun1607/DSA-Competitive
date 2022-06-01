class Solution {
public:
    vector<int> dijkstra(vector<pair<int,int>> *adj, int n, int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n+1, -1);
        pq.push({0, src});
        while(!pq.empty()){
            auto t=pq.top();
            int vertex=t.second;
            int weight=t.first;
            pq.pop();
            if(vis[vertex]==-1){
                vis[vertex]=weight;
                for(auto i:adj[vertex]){
                    if(vis[i.first]==-1){
                        pq.push({i.second+weight, i.first});
                    }
                }
            }
        }
        return vis;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto i:times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dist=dijkstra(adj,n,k);
        int ans=-1;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==-1) return -1;
            ans=max(ans, dist[i]);
        }
        return ans;
    }
};