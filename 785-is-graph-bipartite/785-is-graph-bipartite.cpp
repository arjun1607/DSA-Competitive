class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n, -1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                queue<int> q;
                visited[i]=1;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int it : graph[node]){
                        if(visited[it]==-1){
                            visited[it]=(visited[node]==1)?2:1;
                            q.push(it);
                        }else if(visited[node]==visited[it] ){
                            return false;
                        }
 
                    }
                }
            }
        }
        return true;
    }
};