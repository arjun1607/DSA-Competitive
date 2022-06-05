class Solution {
public:
    bool isvalid(vector<string> &grid, int x, int y, int n){
        for(int i=x-1;i>=0;i--) if(grid[i][y]=='q') return false;
        for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--)  if(grid[i][j]=='q') return false;
        for(int i=x-1, j=y+1; i>=0 && j<n; i--, j++)  if(grid[i][j]=='q') return false;
        return true;
    }
    void helper(int i, vector<string> &grid, int n, int &ans){
        if(i==n) {
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(isvalid(grid, i, j, n)){
                grid[i][j]='q';
                helper(i+1, grid, n, ans);
                grid[i][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        int ans=0;
        helper(0, grid, n, ans);
        return ans;
    }
};