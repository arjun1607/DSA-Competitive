class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        // for answer to be true, s should have all 2^k unique binary codes as its substring
        unordered_set<string> got;
        long need = 1<<k;
        for(int i=0;i<=s.size()-k;i++){
            got.insert(s.substr(i, k));
        }
        return got.size() == need;
    }
};