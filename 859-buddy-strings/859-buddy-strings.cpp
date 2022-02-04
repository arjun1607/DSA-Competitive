class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size()) return false;
        set<char> s1, s2;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=g[i]) {
                s1.insert(s[i]);
                s2.insert(g[i]);
                count++;
            }
        }
        if(count==1) return false;
        else if(count==2 && s1==s2) return true;
        else if(count==0){
            s1.clear();
            for(char c:s) s1.insert(c);
            return s1.size()<s.size();
        }
        return false;
        
    }
};