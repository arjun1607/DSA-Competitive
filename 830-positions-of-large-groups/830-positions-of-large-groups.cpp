class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> v;
        int i=0, j=0;
        while(j<s.size()){
            if(s[i]==s[j]) j++;
            else{
                if(j-i>=3) v.push_back({i,j-1});
                i=j;
            }
        }
        if(j-i>=3) v.push_back({i, j-1});
        return v;
    }
};