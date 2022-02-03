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
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> s=mv(s1), t=mv(s2);
        unordered_map<string,int> m;
        for(auto i:s) m[i]++;
        vector<string> ans;
        for(auto i:t) m[i]++;
        for(auto i:m) if(i.second==1) ans.push_back(i.first);
        return ans;
    }
};
































