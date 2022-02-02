class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> m;
        for(char c:stones) m[c]++;
        int ans=0;
        for(char c:jewels) ans+=m[c];
        return ans;
    }
};