class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> m;
        for(int i=0;i<s.size();i++) m[s[i]].push_back(i);
        int ans=0;
        bool unique=true;
        for(auto i:m) {
            if(i.second.size()>1) unique=false;
            ans=max(ans, i.second.back()-i.second.front()-1);
        }
        return (!unique)?ans:-1;
    }
};