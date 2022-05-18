class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(char c:s) if(isalnum(c)) t+=tolower(c);
        for(int i=0, j=t.size()-1; i<j;i++, j--) if(t[i]!=t[j]) return false;
        return true;
    }
};