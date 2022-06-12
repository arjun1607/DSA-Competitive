class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> map;
        for(auto &i:mappings){
            map[i[0]].insert(i[1]);
        }   
        int n=s.size(), m=sub.size();
        for(int i=0;i<n-m+1;i++){
            bool ok=true;
            for(int k=0; k<m; k++){
                if(sub[k]==s[i+k]  ||  map[sub[k]].find(s[i+k])!=map[sub[k]].end()) continue;
                else{
                    ok=false;
                    break;
                }
            }
            if(ok) return true;
        }
        return false;
    }
};