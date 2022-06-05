class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {      
        int n=grid.size(), m=grid[0].size();
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) q.push({i, j});
            }
        }
        int ans=INT_MIN;
        int x[4]={-1, 0, 1, 0};
        int y[4]={0, -1, 0, 1};
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int i=t[0], j=t[1], lvl=t[2];
            for(int k=0;k<4;k++){
                int ni=i+x[k], nj=j+y[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==0){
                       grid[ni][nj]=grid[i][j]+1;
                       ans=max(ans, grid[ni][nj]);
                       q.push({ni, nj});
                } 
            }
        }
        return (ans==INT_MIN)?-1:ans-1;
    }
};