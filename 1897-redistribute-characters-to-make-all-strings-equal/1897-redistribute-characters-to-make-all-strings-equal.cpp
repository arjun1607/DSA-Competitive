class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> m;
        for(auto i:words){
            for(char c:i) m[c]++;
        }
        for(auto i:m) if(i.second%words.size()!=0) return false;
        return true;
    }
};