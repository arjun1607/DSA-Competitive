class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1, m2;
        for(auto i:words1) m1[i]++; for(auto i:words2) m2[i]++;
        int ans=0;
        for(auto i:m1) if(m1[i.first]==1 && m2[i.first]==1) ans++;
        return ans;
    }
};