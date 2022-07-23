class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int,int> m;
        for(int i:a)
            for(int j:b)
                m[i+j]++;
        
        int ans=0;
        for(int i:c)
            for(int j:d)
                ans+=m[-(i+j)];
        return ans;
    }
};