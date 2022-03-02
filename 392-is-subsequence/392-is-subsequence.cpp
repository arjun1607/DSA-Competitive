class Solution {
public:
    bool isSubsequence(string s, string t, int i=0) {
        unordered_map<char, vector<int>> m;
        for(int i=0;i<t.size();i++) m[t[i]].push_back(i);
        int prev=-1;
        for(char ch:s){
            if(m.find(ch)==m.end()) return false;
            auto v=m[ch];
            int pos=upper_bound(v.begin(), v.end(), prev)-v.begin();
            if(pos==v.size()) return false;
            prev=v[pos];
        }
        return true;
    }
};