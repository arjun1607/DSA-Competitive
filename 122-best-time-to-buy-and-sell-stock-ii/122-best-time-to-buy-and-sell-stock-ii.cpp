class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0], sell=prices[0], ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i] >= sell) sell=prices[i];
            else{
                ans+=sell-buy;
                sell=prices[i];
                buy=prices[i];
            }
        }
        return ans+sell-buy;
    }
};