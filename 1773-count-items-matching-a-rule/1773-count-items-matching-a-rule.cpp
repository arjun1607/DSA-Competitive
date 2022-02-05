class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> m; 
        m["type"]=0; m["color"]=1; m["name"]=2;
        int ans=0;
        for(auto i:items){
            if(i[m[ruleKey]]==ruleValue) ans++;
        }
        return ans;
    }
};