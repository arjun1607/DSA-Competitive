class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        /*
        for(int i=0;i<n;i++){
            int currfuel=0, j=i;
            while(j<n+i){
                currfuel += (gas[j%n]-cost[j%n]);
                if(currfuel < 0) break;
                j++;
            }
            if(j>=n && j%n==i) return i;
        }
        return -1;
        */
        
        /*
              int sum=accumulate(gas.begin(),gas.end(),0);
        int ans=accumulate(cost.begin(),cost.end(),0);
        if(ans>sum) return -1;
        else{
          int n=cost.size();
          vector<int> dp(2*n);
          for(int i=0;i<n;i++){
              dp[i]=gas[i]-cost[i];
          }
          for(int i=n;i<2*n;i++){
             dp[i]=dp[i-n];
          }
          int i=0,j=-1;
          int ans=-1,sum=0,k=0;
          for(int i=0;i<2*n;i++)
          {
             sum+=dp[i];
             k++;
             if(k==n && sum>=0)
             {
                ans=j+1;
                break;
             }
             if(sum<0)
             {
               j=i,k=0,sum=0;
             }
          }
          return ans;
        }
        */
        
        int i, j;
        for(i=0;i<n;i+=j){
            int currfuel=0;
            for(j=1;j<=n;j++){
                int k=(i+j-1);
                currfuel += (gas[k%n]-cost[k%n]);
                if(currfuel < 0) break;
            }
            if(j>n) return i;
        }
        return -1;
    }
};