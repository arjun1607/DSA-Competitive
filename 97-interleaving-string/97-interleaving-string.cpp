class Solution {
public:
    bool memo(int i, int j, int k, string a, string b, string c, vector<vector<vector<int>>> &dp){
        if(k==c.size()){
            if(i==a.size() && j==b.size()) return true;
            return false;
        }
        if(i==a.size() && j==b.size()) return false;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        bool opt1=false, opt2=false;
        if(a[i]==c[k]) opt1=memo(i+1, j, k+1, a, b, c, dp);
        if(b[j]==c[k]) opt2=memo(i, j+1, k+1, a, b, c, dp);
        return dp[i][j][k] = opt1 || opt2;
    }
    bool isInterleave(string a, string b, string c) {
        vector<vector<vector<int>>> dp(a.size()+1, vector<vector<int>>(b.size()+1, vector<int>(c.size()+1, -1)));
        return memo(0, 0, 0, a, b, c, dp);
    }
};