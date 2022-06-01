typedef pair<int,pair<int,int>> pii;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<int>> dis(n, vector<int>(m, -1));
        
        if(grid[0][0]==0)
            pq.push({0,{0,0}});  // {cost, i, j}
        else 
            pq.push({1,{0,0}});
            
        int x[4] = {0, 1, 0, -1};
        int y[4] = {1, 0, -1, 0};
        while(!pq.empty()){
            auto t=pq.top();
            int wt=t.first;
            int i=t.second.first;
            int j=t.second.second;
            pq.pop();
            if(dis[i][j]==-1){
                dis[i][j]=wt;
                for(int k=0;k<4;k++){
                    if(i+x[k]>=0 && i+x[k]<n && j+y[k]>=0 && j+y[k]<m){
                        if(dis[i+x[k]][j+y[k]]==-1){
                            pq.push({grid[i+x[k]][j+y[k]] + wt, {i+x[k], j+y[k]}});
                        }
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};












