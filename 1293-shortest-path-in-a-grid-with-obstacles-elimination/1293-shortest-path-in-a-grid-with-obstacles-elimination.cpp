class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int allowed) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(allowed+1, false)));
        queue<vector<int>>  q;
        q.push({0,0,grid[0][0],0});
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int i=t[0], j=t[1];
            int count=t[2], lvl=t[3];
            if(i==n-1 && j==m-1) return lvl;
            for(int k=0;k<4;k++){
                int ni=i+x[k], nj=j+y[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    int newcount = count+grid[ni][nj];
                    if(newcount<=allowed && !vis[ni][nj][newcount]){
                        q.push({ni, nj, newcount, lvl+1});
                        vis[ni][nj][newcount]=true;
                    }
                }
            }
        }
        return -1;
    }
};