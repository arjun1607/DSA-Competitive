class Solution {
public:
    int getLucky(string s, int k) {
        int num=0;
        for(char c:s){
            int t=c-'a'+1;
            num += (t/10 + t%10);
        }
        k--;
        while(k--){
            int t=num, sum=0;
            while(t!=0){
                sum+=t%10;
                t=t/10;
            }
            num=sum;
        }
        return num;
    }
};