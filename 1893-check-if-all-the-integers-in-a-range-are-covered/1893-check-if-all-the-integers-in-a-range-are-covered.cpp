class Solution {
public:
    bool isCovered(vector<vector<int>>& r, int left, int right) {
        set<int> s; for(int i=left; i<=right;i++) s.insert(i);
        for(auto i:r){
            for(int k=i[0];k<=i[1];k++){
                if(s.find(k)!=s.end()) s.erase(k);
            }
        }
        return s.size()==0;
    }
};