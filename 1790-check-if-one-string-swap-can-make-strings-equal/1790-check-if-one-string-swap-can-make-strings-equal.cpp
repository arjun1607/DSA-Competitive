class Solution {
public:
    bool areAlmostEqual(string s, string t) {
        if(s.size()!=t.size()) return false;
        int count=0;
        set<int> s1, s2;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=t[i]) {
                count++;
                s1.insert(s[i]);
                s2.insert(t[i]);
            }
        }
        return count==0||(s1==s2 && count==2);
    }
};