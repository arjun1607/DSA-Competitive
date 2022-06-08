class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> adj[n];
        for(auto i:prereq){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> indegree(n, 0);
        for(auto i:prereq){
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int count=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            count++;
            for(auto i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        return (count==n)?true:false;
    }
};