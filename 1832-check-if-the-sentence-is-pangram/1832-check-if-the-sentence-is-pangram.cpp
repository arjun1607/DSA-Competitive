class Solution {
public:
    bool checkIfPangram(string sen) {
        set<char> s; for(auto c:sen) s.insert(c);
        return s.size()==26;
    }
};