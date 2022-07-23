class Solution {
public:
    int minBitFlips(int s, int e) {
        int x=s^e;
        int c=0;
        while(x!=0){
            c++;
            int rsbm=x&(-x);
            x=x-rsbm;
        }
        return c;
    }
};