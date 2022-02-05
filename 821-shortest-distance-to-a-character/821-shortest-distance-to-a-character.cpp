class Solution {
public:
    vector<int> shortestToChar(string t, char c) {
        set<int> s; for(int i=0;i<t.size();i++) if(t[i]==c) s.insert(i);
        vector<int> ans(t.size());
        for(int i=0;i<ans.size();i++){
            int mi=INT_MAX;
            for(int j:s) mi=min(mi, abs(j-i));
            ans[i]=mi;
        }
        return ans;
    }
};