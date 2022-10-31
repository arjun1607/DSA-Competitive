class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& grid) {
        unordered_map<int,int> m;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(m.find(i-j)==m.end()) m[i-j] = grid[i][j];
                else{
                    if(m[i-j]!=grid[i][j]) return false;
                }
            }
        }
        return true;
    }
};
