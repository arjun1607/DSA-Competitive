class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v= roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
        vector<long long> dis(n,LLONG_MAX);
        vector<int> count(n,0);
        dis[0] = 0;
        count[0] = 1;
        que.push({0,0});
        while(!que.empty()){
            auto node = que.top();
            que.pop();
            if(node.first == dis[node.second]) {
            for(auto neighbors : adj[node.second]){
                long long curr = dis[neighbors.first];
                long long newd = dis[node.second] + neighbors.second;
                if(newd < curr){
                    count[neighbors.first] = count[node.second];
                    dis[neighbors.first] = newd;
                    que.push({newd,neighbors.first});
                }
                else if(newd == curr){
                    count[neighbors.first] = (count[neighbors.first]%mod + count[node.second]%mod)%mod;
                    
                }
            }
            }
        }
        
        return count[n-1];
    }
};