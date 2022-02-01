class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> min(n), maxx(n);
        min[0]=prices[0]; maxx[n-1]=prices[n-1];
        for(int i=1;i<n;i++){
            min[i]=(prices[i] < min[i-1])?prices[i]:min[i-1];
        }
        for(int j=n-2;j>=0;j--){
            maxx[j]=(prices[j] > maxx[j+1])?prices[j]:maxx[j+1];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(min[i] < maxx[i]){
                ans=max(ans, maxx[i]-min[i]);
            }
        }
        return ans;
    }
};