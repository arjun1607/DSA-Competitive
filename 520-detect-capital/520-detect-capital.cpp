class Solution {
public:
    bool detectCapitalUse(string s) {
        int x=0, y=0;
        for(char c:s){
            if(c>='a' && c<='z') x++;
            else y++;
        }
        return x==s.size() ||  y==s.size() || (y==1 && (s[0]>='A' && s[0]<='Z'));
    }
};