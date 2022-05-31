class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n, -1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                        int node=q.front();
                        int grp=vis[node];
                        q.pop();
                        for(int &neigh:graph[node]){
                            if(vis[neigh]!=-1 && vis[neigh]==grp) return false;
                            else if(vis[neigh]==-1){
                                vis[neigh]=(grp==1)?2:1;
                                q.push(neigh);
                            }
                        }
                }
            }
        }
        return true;
    }
};