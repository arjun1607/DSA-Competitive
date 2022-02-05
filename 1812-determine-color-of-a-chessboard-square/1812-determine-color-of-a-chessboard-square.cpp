class Solution {
public:
    bool squareIsWhite(string s) {
        if((s[0]-'a')%2==0 && (s[1]-'0')%2==0) return true;
        if((s[0]-'a')%2==1 && (s[1]-'0')%2==1) return true;
        return false;
    }
};