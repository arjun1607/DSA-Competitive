class Solution {
public:
    string restoreString(string s, vector<int>& idx) {
        string t(s.size(),' ');
        for(int i=0;i<s.size();i++){
            t[idx[i]]=s[i];
        }
        return t;
    }
};