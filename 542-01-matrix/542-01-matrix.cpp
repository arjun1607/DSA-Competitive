class Solution {
public:
    int n, m;
    int x[4]={-1, 0, 1, 0};
    int y[4]={0, -1, 0, 1};
    void bfs(vector<vector<int>> &grid, queue<vector<int>> &q, vector<vector<int>> &ans){
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int i=t[0], j=t[1], lvl=t[2];
            if(grid[i][j]==1 && ans[i][j]==-1){
                ans[i][j]=lvl;
            }
            for(int k=0;k<4;k++){
                int ni=i+x[k], nj=j+y[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && ans[ni][nj]==-1){
                    cout<<ni<<" "<<nj<<endl;
                    q.push({ni, nj, lvl+1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        /*
        Because one full BFS loop that starts at 1 and searches for 0 only sets distance for that one 1. 
        But if you start at 0 and go outward, you can set four 1's distances at a time.
        */
        n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i, j, 0});
                    ans[i][j]=0;
                }
            }
        }
        bfs(grid, q, ans);
        return ans;
    }
};