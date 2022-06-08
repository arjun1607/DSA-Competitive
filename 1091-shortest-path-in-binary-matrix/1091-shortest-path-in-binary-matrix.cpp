class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return -1;
        int n=grid.size(), m=grid[0].size();
        queue<vector<int>> q;
        grid[0][0]=1;
        q.push({0, 0, 1});
        int x[8]={-1, -1, 0, 1, 1, 1, 0, -1};
        int y[8]={0, -1, -1, -1, 0, 1, 1, 1};
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int i=t[0], j=t[1], lvl=t[2];
            if(i==n-1 && j==m-1) return lvl;
            for(int k=0;k<8;k++){
                int ni=i+x[k], nj=j+y[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==0){
                    grid[ni][nj]=1;
                    q.push({ni, nj, lvl+1});
                }
            }
        }
        return -1;
    }
};