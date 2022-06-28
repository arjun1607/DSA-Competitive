class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minc=prices[0], profit=0;
        for(int i=1;i<prices.size();i++){
            profit = max(profit, prices[i]-minc);
            minc = min(minc, prices[i]);
        }
        return profit;
    }
};