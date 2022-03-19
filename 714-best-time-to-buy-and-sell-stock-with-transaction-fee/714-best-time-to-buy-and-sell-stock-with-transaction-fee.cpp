class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int bsp = -prices[0], ssp = 0, ans=0;
        for(int i=1;i<prices.size();i++){
            int new_bsp = max(bsp, ssp - prices[i]);
            int new_ssp = max(ssp, bsp + prices[i] - fee);
            ans=max(ans, new_ssp);
            bsp=new_bsp;
            ssp=new_ssp;        
        }
        return ans;
    }
};