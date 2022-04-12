class Solution {
public:
    bool memo(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==s.size() && j==p.size()) {
            return true;
        }
        if(j==p.size()) {
            return false;
        }
        if(i==s.size()){
            if(p[j]=='*') j++;
            if( (p.size()-j) % 2 == 1) return false;
            int c=1;
            for(int jj=j;jj<p.size();jj++){
                if( (c==1 && p[jj]=='*') || (c==-1 && p[jj]!='*')) {
                    return false;
                }
                c*=-1;
            }
            return true;
        }
         
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] || p[j]=='.'){
            if(j+1<p.size() && p[j+1]=='*'){
                return dp[i][j] = memo(i+1, j+1, s, p, dp) || memo(i, j+2, s, p, dp);
            }
            return dp[i][j] = memo(i+1, j+1, s, p, dp);
        }
        else if(p[j]=='*'){
            if(s[i]==p[j-1] || p[j-1]=='.')
                return dp[i][j] = (memo(i, j+1, s, p, dp) || memo(i+1, j, s, p, dp));
            else 
                return dp[i][j]=memo(i, j+1, s, p, dp);
        }
        else if(j+1<p.size() && p[j+1]=='*')
            return dp[i][j] = memo(i, j+2, s, p, dp);
    
        return dp[i][j] = false;
       
    }
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memo(0, 0, s, p, dp);
    }
};