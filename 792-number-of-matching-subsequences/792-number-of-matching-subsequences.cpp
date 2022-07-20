class Solution {
public:
    int numMatchingSubseq(string str, vector<string>& words) {
        unordered_map<char, vector<int>> m;
        for(int i=0;i<str.size();i++){
            m[str[i]].push_back(i);
        }
        int ans=0;
        for(auto &s:words){
            int prev=-1;
            bool subseq=true;
            for(char &c:s){
                if(m.find(c)==m.end()) {
                    subseq=false; break;
                }
                auto &v = m[c];
                int idx = upper_bound(v.begin(), v.end(), prev) - v.begin();
                if(idx==v.size()){
                    subseq=false; break;
                }            
                prev=v[idx];
            }
            if(subseq) ans++;
            
        }
        return ans;
    }
};