class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<int> min(p.size()), m(p.size());
        // min[0]=p[0]; m[p.size()-1]=p[p.size()-1];
        // for(int i=1;i<p.size();i++) min[i]=(p[i]<min[i-1])?p[i]:min[i-1];    
        // for(int i=p.size()-2;i>=0;i--) m[i]=(p[i]>m[i+1])?p[i]:m[i+1];
        // int ans=0;
        // for(int i=0;i<p.size();i++) ans=max(ans, m[i]-min[i]);
        // return ans;
        
        int minPrice=INT_MAX, ans=0;
        for(int price:prices){
            minPrice=min(minPrice, price);
            int ifSoldToday=price-minPrice;
            ans=max(ans, ifSoldToday);
        }
        return ans;
    }
};