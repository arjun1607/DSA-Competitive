class Solution {
public:
    vector<vector<string>> ans;
    bool isvalid(int x, int y, vector<string> &grid){
        for(int i=x-1;i>=0;i--){
            if(grid[i][y]=='Q') return false;
        }
        for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--){
            if(grid[i][j]=='Q') return false;
        }
        for(int i=x-1, j=y+1; i>=0 && j<grid[0].size(); i--, j++){
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(int i, vector<string> &grid, int n){
        if(i==n){
            ans.push_back(grid);
            return;
        }
            for(int j=0;j<n;j++){
                if(isvalid(i, j, grid)){
                    grid[i][j]='Q';
                    helper(i+1, grid, n);
                    grid[i][j]='.';
                }
            }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        helper(0, grid, n);
        return ans;
    }
};