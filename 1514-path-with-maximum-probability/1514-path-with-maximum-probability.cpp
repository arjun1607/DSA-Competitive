class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        vector<pair<int, double>> adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], prob[i]});
            adj[edges[i][1]].push_back({edges[i][0], prob[i]});
        }
        vector<double> vis(n+1, -1);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            double wt = t.first;
            int vertex = t.second;
            if(vis[vertex]==-1){
                vis[vertex] = wt;
                for(auto i:adj[vertex]){
                    if(vis[i.first] == -1){
                        pq.push({i.second * wt, i.first});
                    }
                }
            }
        }
        if(vis[end]==-1) return 0.0;
        return vis[end];
    }
};















