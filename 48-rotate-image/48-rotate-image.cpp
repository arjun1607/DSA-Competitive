class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                swap(m[i][j], m[j][i]);
        }
        for(auto &v:m){
            reverse(v.begin(), v.end());
        }
    }
};