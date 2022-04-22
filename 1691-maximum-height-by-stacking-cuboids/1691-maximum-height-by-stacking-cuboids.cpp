class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        for(auto &v:c) sort(v.begin(), v.end(), greater<int>());
        sort(c.begin(), c.end());
        vector<int> dp(c.size());
        dp[0]=c[0][0];
        int ans=dp[0];
        for(int i=1;i<c.size();i++){
            dp[i]=c[i][0];
            for(int j=0;j<i;j++){
                if(c[j][1] <= c[i][1] && c[j][2] <= c[i][2]) dp[i]=max(dp[i], dp[j]+c[i][0]);
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};


























