class Solution {
public:
    int maxNumberOfBalloons(string s) {
        unordered_map<char,int> m; 
        for(char c:s) if(c=='b' || c=='a' || c=='l' || c=='o' || c=='n') m[c]++;
        if(m['b']==0 || m['a']==0 || m['l']<=1 || m['o']<=1 || m['n']==0) return 0;
        m['l']/=2;
        m['o']/=2;
        int ans=INT_MAX;
        for(auto i:m){
            ans=min(ans, i.second);
        }
        return ans;
    }
};