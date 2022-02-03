class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        /*
        unordered_map<char, vector<int>> m;
        for(int i=0;i<s.size();i++) m[s[i]].push_back(i);
        int ans=0;
        bool unique=true;
        for(auto i:m) {
            if(i.second.size()>1) unique=false;
            ans=max(ans, i.second.back()-i.second.front()-1);
        }
        return (!unique)?ans:-1;
        */
        // SINGLE TRAVERSAL
        unordered_map<char,int> m;
        int len=-1;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()) len=max(len, i-m[s[i]]-1);
            else m[s[i]]=i;
        }
        return len;
    }
};