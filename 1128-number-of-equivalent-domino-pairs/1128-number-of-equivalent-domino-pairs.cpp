class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        for(auto &i:d) sort(i.begin(), i.end());
        map<vector<int>,int> m; 
        for(auto i:d) m[i]++;
        int ans=0;
        for(auto i:m){
            if(i.second>=0) ans+=(i.second*(i.second-1)/2);
        }
        return ans;
    }
};