class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
        vector<int> adj[n+1];
        vector<int> indegree(n+1, 0);
        for(auto i:r){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        vector<int> cost(n+1, 0);
        for(int i=1;i<=n;i++){
            cost[i]=time[i-1];
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i:adj[curr]){
                cost[i]=max(cost[i], cost[curr]+time[i-1]);
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        return *max_element(cost.begin(), cost.end());
    }
};