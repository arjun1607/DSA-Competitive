class Solution {
public:
    int numberOfSteps(int n) {
        int ans=0;
        while(n!=0){
            if(n&1) n-=1;
            else n>>=1;
            ans++;
        }
        return ans;
    }
};