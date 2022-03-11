class Solution {
public:
   static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0])
            return a[1] > b[1];
        
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);
        vector<int> dp;
        for(auto val:v){
            auto it=lower_bound(dp.begin(), dp.end(), val[1]);
            if(it==dp.end()) dp.push_back(val[1]);
            else *it=val[1];
        }
        return dp.size();
    }
};