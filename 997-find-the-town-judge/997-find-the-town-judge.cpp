class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        set<int> s;
        for(auto i:t) s.insert(i[0]);
        if(s.size()==n) return -1;
        int ans;
        for(int i=1;i<=n;i++) {
            if(s.find(i)==s.end()) {
                ans=i; break;
            }            
        }
        vector<bool> v(n+1, false);
        for(auto i:t){
            if(i[1]==ans) v[i[0]]=true;
        }
        bool ok=true;
        for(int i=1;i<=n;i++){
            if(i!=ans && v[i]==false) return -1;
        }
        return ans;
    }
};