class Solution {
public:
    int mst(vector<pair<int,int>> *adj, int n){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> vis(n, false);
        pq.push({0,0});
        int cost=0;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int weight=t.first;
            int vertex=t.second;
            if(!vis[vertex]){
                cost+=weight;
                vis[vertex]=true;
                for(auto i:adj[vertex]){
                    if(!vis[i.first]){
                        pq.push({i.second, i.first});
                    }
                }
            }
        }
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }
        return mst(adj, n);
    }
};