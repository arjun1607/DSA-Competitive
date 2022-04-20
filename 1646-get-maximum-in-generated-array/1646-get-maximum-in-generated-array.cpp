class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        vector<int> v(n+1, 0);
        v[1]=1;
        int i=1, ans=1;
        while(i<=n){
            if(2*i<=n) {
                v[2*i]=v[i];
                ans=max(ans, v[2*i]);
            }
            if(2*i+1<=n) {
                v[2*i+1]=v[i]+v[i+1];
                ans=max(ans, v[2*i+1]);
            }
            i++;
        }
        return ans;
    }
};