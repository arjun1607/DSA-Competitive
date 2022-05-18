class Solution {
public:
    string pushDominoes(string s) {
        s='L'+s+'R';
        string ans="L";
        for(int i=0, j=1; j<s.size(); j++){
            if(s[j]=='.') continue;
            
            int n=j-i-1;
            if(s[i]=='L' && s[j]=='L')
                ans+=string(n, 'L');
            else if(s[i]=='L' && s[j]=='R')
                ans+=string(n, '.');
            else if(s[i]=='R' && s[j]=='R')
                ans+=string (n, 'R');
            else
                ans += string(n/2, 'R') + string(n%2, '.') + string(n/2, 'L');
            
            ans+=s[j];
            i=j;
        }
        ans.pop_back();
        string finalans = ans.substr(1);
        return finalans;
    }
};