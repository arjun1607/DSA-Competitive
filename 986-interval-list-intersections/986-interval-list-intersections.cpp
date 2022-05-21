class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& sec) {
        vector<vector<int>> ans;
        int  i=0, j=0;
        while(i<first.size() && j<sec.size()){
            if(first[i][0]<=sec[j][1] && sec[j][0]<=first[i][1]){
                int s=max(first[i][0], sec[j][0]);
                int e=min(first[i][1], sec[j][1]);
                ans.push_back({s,e});
            }
            if(first[i][1] < sec[j][1]) i++;
            else j++;
        }
        return ans;
    }
};