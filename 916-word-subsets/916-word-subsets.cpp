class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> m;
        for(auto i:words2){
            unordered_map<char, int> p;
            for(auto j:i){
                p[j]++;
            }
            for(auto it:p){
                int freq = it.second;
                char c = it.first;
                if(m[c] < freq){
                    m[c] = freq;
                }
            }
        }
        vector<string> ans;
        for(auto i:words1){
            unordered_map<char, int> m2;
            for(char j:i) m2[j]++;
            bool ok=true;
            for(auto i:m){
                int freq = i.second;
                char c = i.first;
                if(m2[c] < freq){
                    ok=false;
                    break;
                }
            }
            if(ok) ans.push_back(i);
        }
        return ans;
    }
};