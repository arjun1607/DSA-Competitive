class Solution {
public:
    int f(string &s){
        for(char &c:s) { int n=c-'a'; c=to_string(n)[0]; }
        return stoi(s);
    }
    bool isSumEqual(string x, string y, string z) {
        int a=f(x), b=f(y), c=f(z);
        return a+b==c;
    }
};