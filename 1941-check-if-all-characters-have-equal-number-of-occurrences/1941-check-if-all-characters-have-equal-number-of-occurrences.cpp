class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int> m;
        for(char c:s) m[c]++;
        int val=m.begin()->second;
        for(auto i:m){
            if(i.second!=val) return false;
        }
        return true;
    }
};