class Solution {
public:
    string thousandSeparator(int n) {
        if(n<1000) return to_string(n);
        int l=log10(n)+1;
        int r=l%3;
        string t=to_string(n), ans="";
        if(r>0) {
            ans+=t.substr(0, r);
            ans+='.';
        }
        int start=0;
        if(r>0) start=r;
        int c=0;
        while(start < t.size()){
            ans+=t[start];
            c++;
            start++;
            if(c==3 && start!=t.size()) { ans+='.'; c=0; }
        }
        return ans;
    }
};