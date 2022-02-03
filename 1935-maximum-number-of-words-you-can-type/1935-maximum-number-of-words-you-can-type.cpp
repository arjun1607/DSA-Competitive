class Solution {
public:
    vector<string> mv(string s){
        vector<string> vs;
        string t="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){ vs.push_back(t); t=""; }
            else t+=s[i];
        }
        vs.push_back(t);
        return vs;
    }
    int canBeTypedWords(string text, string b) {
        vector<string> s=mv(text);
        set<char> ss; for(char c:b) ss.insert(c);
        int count=0;
        for(auto i:s){
            for(char c:i) {
                if(ss.find(c)!=ss.end()){ count++; break;}
            }
        }
        return s.size()-count;
    }
};