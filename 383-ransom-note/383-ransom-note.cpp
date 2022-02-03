class Solution {
public:
    bool canConstruct(string r, string z) {
        unordered_map<char,int> m;
        for(char c:z) m[c]++;
        for(char c:r){
            if(m.find(c)==m.end()) return false;
            m[c]--;
            if(m[c]<0) return false;
        }
        return true;
    }
};