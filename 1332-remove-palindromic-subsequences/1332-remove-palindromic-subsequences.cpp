class Solution {
public:
    int removePalindromeSub(string s) {
        if(s=="") return 0;
        string t=s; reverse(t.begin(), t.end());
        if(t==s) return 1;
        else return 2;
    }
};