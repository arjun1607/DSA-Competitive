class Solution {
public:
    string replaceDigits(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) ans+=s[i];
            else if(isdigit(s[i])) ans+=((char)(s[i-1]+s[i]-'0'));
        }
        return ans;
    }
};