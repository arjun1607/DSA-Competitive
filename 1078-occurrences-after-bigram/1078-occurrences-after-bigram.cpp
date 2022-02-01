class Solution {
public:
    vector<string> findOcurrences(string t, string f, string s) {
        vector<string> v;
        string x="";
        for(int i=0;i<t.size();i++){
            if(t[i]==' '){
                v.push_back(x);
                x="";
            }else x+=t[i];
        }
        v.push_back(x);
        for(auto i:v) cout<<i<<" ";
        vector<string> ans;
        for(int i=0;i<v.size()-2;i++){
            if(v[i]==f && v[i+1]==s) ans.push_back(v[i+2]);
        }
        return ans;
    }
};