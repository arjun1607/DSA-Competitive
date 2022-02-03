class Solution {
public:
    int secondHighest(string str) {
        set<int> s;
        int  max=INT_MIN, secmax=INT_MIN;
        for(char c:str){
            int n=c-'0';
            if(n>=0 && n<=9) {
                if(s.find(n)==s.end()){
                   if(n>max){
                        secmax=max;
                        max=n;
                   }else if(n>secmax){
                        secmax=n;
                   }
                }
                s.insert(n);
            }
        }
        return (secmax==INT_MIN)?-1:secmax;
    }
};