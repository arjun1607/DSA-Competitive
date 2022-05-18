class Solution {
public:
    bool check(string s){
        for(int i=0, j=s.size()-1; i<j; i++, j--) if(s[i]!=s[j]) return false;
        return true;
    }
    bool validPalindrome(string s) {
        int i=0, j=s.size()-1;
        bool ans=true;
        for(int i=0, j=s.size()-1; i<j; i++, j--){
            if(s[i]!=s[j]){
                ans=check(s.substr(i, j-i)) || check(s.substr(i+1, j-i));  
                break;
            }
        }
        return ans;
    }
};