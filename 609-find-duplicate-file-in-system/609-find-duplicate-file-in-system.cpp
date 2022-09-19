class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for(string &s:paths){
            int space = -1, i=0;
            string path = "";
            bool p=false;
            while(i<s.size()){
                if(s[i] == ' ') {
                    p=true;
                    space = i;
                }
                if(p==false) {
                    path += s[i];
                }
                else if(s[i-1] == '('){
                    string fname = s.substr(space+1, i-space-2);
                    string content = "";
                    while(s[i]!=')') content += s[i++];
                    string t = path + '/' + fname ;
                    m[content].push_back(t);
                }
                i++;
            }
        }
        vector<vector<string>> ans;
        for(auto &i:m) if(i.second.size() > 1) ans.push_back(i.second);
        return ans;
    }
};