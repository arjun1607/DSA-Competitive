class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        vector<string> copy(strs);
        for(auto &s:copy) sort(s.begin(), s.end());
        vector<vector<string>> ans;
        for(int i=0;i<copy.size();i++){
            vector<string> sans;
            string curr=copy[i];
            
            if(curr=="VISITED") continue;
            
            for(int j=0;j<copy.size();j++){
                if(copy[j]==curr){
                    sans.push_back(strs[j]);
                    copy[j]="VISITED";
                }
            }
            ans.push_back(sans);
        }
        return ans;
        */
        
        unordered_map<string, vector<string>> m;
        for(auto &s:strs){
            string t=s; sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &it:m) ans.push_back(it.second);
        return ans;
        
    }
};