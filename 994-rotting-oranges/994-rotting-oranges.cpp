class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        int steps=0;
        int x[4]={-1, 0, 1, 0};
        int y[4]={0, -1, 0, 1};
        
        while(!q.empty()){
            int size=q.size();
            bool fresh=false;
            while(size-->0){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+x[k], nj=j+y[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                        fresh=true;
                        grid[ni][nj]=2;
                        q.push({ni, nj});
                    }
                }
            }
            if(fresh) steps++;
        }
        for(auto i:grid){
            for(int j:i) if(j==1) return -1;
        }
        return steps;
    }
};