class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m; for(int i:arr) m[i]++;
        int ans=-1, l=INT_MIN;
        for(auto i:m){
            if(i.second==i.first && i.first>l) { ans=i.first; l=i.first; }
        }
        return ans;
    }
};