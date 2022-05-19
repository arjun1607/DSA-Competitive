class Solution {
public:
    vector<vector<int>> direc = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>> &m, int i, int j, int val, 
            vector<vector<bool>> &vis, vector<vector<int>> &memo){
        if(i<0 || j<0 || i==m.size() || j==m[0].size() || vis[i][j]==true || m[i][j]<=val) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int tempans=0;
        vis[i][j]=true;
        for(auto &it:direc)
            tempans = max(tempans, dfs(m, i+it[0], j+it[1], m[i][j], vis, memo));
        vis[i][j]=false;
        return memo[i][j]=tempans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& m) {
        vector<vector<bool>> vis(m.size(), vector<bool>(m[0].size(), false));
        int ans=0;
        // DFS from all points
        vector<vector<int>> memo(m.size(), vector<int>(m[0].size(), -1));
        for(int i=0;i<m.size();i++)
            for(int j=0;j<m[0].size();j++)
                ans=max(ans, dfs(m, i, j, INT_MIN, vis, memo));
        return ans;
    }
};