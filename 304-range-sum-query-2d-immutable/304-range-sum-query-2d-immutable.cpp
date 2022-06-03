class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();    
        pre.resize(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+grid[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int sum = pre[r2+1][c2+1]-pre[r1][c2+1]-pre[r2+1][c1]+pre[r1][c1];
        return sum;
    }
};

