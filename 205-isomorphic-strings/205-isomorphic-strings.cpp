class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end() && m[s[i]]!=t[i]) return false;
            else m[s[i]]=t[i];
        }
        m.clear();
        for(int i=0;i<t.size();i++){
            if(m.find(t[i])!=m.end() && m[t[i]]!=s[i]) return false;
            else m[t[i]]=s[i];
        }
        return true;
    }
};