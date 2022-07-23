class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        
        bool neg=false;
        long nn=n;
        if(nn<0) {
            neg=true;
            nn=-nn;
        }
        
        double ans = myPow(x, nn/2);
        if(nn%2==0) ans = ans * ans;
        else  ans = ans * ans * x;
        
        if(neg) ans = 1.0/ans;
        
        return ans;
    }
};