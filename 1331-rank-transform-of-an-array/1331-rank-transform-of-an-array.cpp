class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s; for(int i:arr) s.insert(i);
        unordered_map<int,int> m; 
        int c=1;
        for(int i:s){
            m[i]=c;
            c++;
        }
        vector<int> ans; 
        for(auto i:arr) ans.push_back(m[i]);
        return ans;
    }
};