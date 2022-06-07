class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if(x<0) {
            neg=true;
            x=abs(x);
        }
        long long ans=0;
        while(x!=0){
            long long rem=x%10;
            ans = ans*10+rem;
            x=x/10;
        }
        if(neg) {
            ans*=-1;
            if(ans<INT_MIN) return 0;
        }
        return (ans>INT_MAX)?0:ans;
    }
};