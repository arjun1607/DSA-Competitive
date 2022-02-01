class Solution {
public:
    int countPoints(string r) {
        unordered_map<int, set<char>> m;
        for(int i=0;i<r.size();i+=2){
            m[r[i+1]].insert(r[i]);
        }
        int ans=0;
        for(auto i:m) if(i.second.size()==3) ans++;
        return ans;
    }
};