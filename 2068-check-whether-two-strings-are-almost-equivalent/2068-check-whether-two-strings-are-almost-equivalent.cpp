class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> m;
        for(char c:word1) m[c]++;
        for(char c:word2) m[c]--;
        for(auto i:m) if(i.second<-3 || i.second>3) return false;
        return true;
    }
};