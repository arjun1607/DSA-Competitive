class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& t, vector<vector<int>>& memo){
        if(i==0 && j==0) return t[0][0];
        if(memo[i][j]!=-1) return memo[i][j];
        int tleft=INT_MAX, tup=INT_MAX;
        if(j-1>=0) tleft = dfs(i-1, j-1, t, memo); 
        if(j < t[i-1].size()) tup = dfs(i-1, j, t, memo);
        return memo[i][j] = t[i][j] + min(tleft, tup);
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        int ans=INT_MAX;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        for(int j=0; j < t[n-1].size(); j++){
            ans=min(ans, dfs(n-1, j, t, memo));
        }
        return ans;
    }
};