class Solution {
public:
    int mst(vector<pair<int,int>> *adj, int n){
        vector<bool> vis(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int weight = t.first;
            int vertex = t.second;
            if(!vis[vertex]){
                vis[vertex] = true;
                ans += weight;
                for(auto i:adj[vertex]){
                    int neigh = i.first;
                    int neighW = i.second;
                    if(!vis[neigh]){
                        pq.push({neighW , neigh});
                    }
                }
            }
        }
        return  ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return mst(adj, n);
    }
};