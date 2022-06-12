class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> v(26);
        for(string i:ideas){
            v[i[0]-'a'].insert(i.substr(1));
        }
        
        long long result=0;
        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
                auto &setA = v[i];
                auto &setB = v[j];
                
                int common=0;
                for(string s:setA){
                    if(setB.find(s)!=setB.end()) common++;
                }
                
                result += 2*(setA.size()-common)*(setB.size()-common);
            }
        }
        
        return result;
    }
};