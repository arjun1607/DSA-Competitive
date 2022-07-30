class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n, 0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                q.push(i);
                vis[i]=1;
                
                while(!q.empty()){
                    int size=q.size();
                    while(size--){
                        int node = q.front();
                        q.pop();
                        int set = vis[node];
                        for(int i : adj[node]){
                            if(vis[i]==0){
                                vis[i] = (set==1)?2:1;
                                q.push(i);
                            }
                            else if(vis[i]==set) return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};