class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1){
            vector<vector<int>> v;
            v.push_back({1});
            return v;
        }
        
        auto it = generate(n-1);
        
        vector<vector<int>> ans;
        for(auto i:it) ans.push_back(i);
        
        
        auto v=it.back();
        
        vector<int> t;
        int prev=0;
        for(int i=0;i<v.size();i++){
            t.push_back(prev+v[i]);
            prev=v[i];
        }
        t.push_back(prev);
        
        ans.push_back(t);
        
        return ans;
    }
};