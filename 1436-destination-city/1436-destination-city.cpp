class Solution {
public:
    string destCity(vector<vector<string>>& p) {
        unordered_map<string , int> m;
        for(auto i:p){
            m[i[0]]=1;
            if(m.find(i[1])==m.end()) m[i[1]]=0;
        }
        string ans;
        for(auto i:m) if(i.second==0) ans= i.first;
        return ans;
    }
};