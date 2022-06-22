class Solution {
public:
    bool ans=false;
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &vis, int k, string &word){
        if(k==word.size()){
            ans=true;
            return;
        }
        
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j]==true || grid[i][j]!=word[k]){
            return;
        }
 
        vis[i][j]=true;
        dfs(grid, i-1, j, vis, k+1, word);
        dfs(grid, i, j-1, vis, k+1, word);
        dfs(grid, i+1, j, vis, k+1, word);
        dfs(grid, i, j+1, vis, k+1, word);
        vis[i][j]=false;
    }
    bool exist(vector<vector<char>>& grid, string word) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(grid, i, j, vis, 0, word);
            }
        }
        return ans;
    }
};