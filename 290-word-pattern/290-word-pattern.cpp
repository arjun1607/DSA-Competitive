class Solution {
public:
    vector<string> mv(string s){
        vector<string> v;
        string t="";
        for(char c:s){
            if(c==' '){
                v.push_back(t);
                t="";
            }else t+=c;
        }
        v.push_back(t);
        return v;
    }
    bool wordPattern(string p, string s) {
        vector<string> v=mv(s);
        if(p.size()!=v.size()) return false;
        unordered_map<char, string> m;
        set<string> set;
        for(int i=0;i<v.size();i++){
            if(m.find(p[i])!=m.end() && m[p[i]]!=v[i]) return false;
            m[p[i]]=v[i];
            set.insert(v[i]);
        }
        if(set.size()!=m.size()) return false;
        else return true;
    }
};