class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int t) {
        int s=0, g=0; for(int i:a) { if(i<t)s++; else if(i>t)g++; }
        vector<int> ans; for(int i=s;i<a.size()-g;i++) ans.push_back(i);
        return ans;
    }
};