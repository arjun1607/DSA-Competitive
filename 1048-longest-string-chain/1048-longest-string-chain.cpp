class Solution {
public:
    bool compare(string &s, string &t){
// compare if difference between string s & t is only 1 char
        if(s.size()!=t.size()+1) return false;
        int first=0, second=0;
        while(first<s.size()){
            if(second<t.size() && s[first]==t[second]){
                first++;
                second++;
            }else first++;
        }
        return first==s.size() && second==t.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string s, string t){
            return s.size()<t.size();
        });
        for(auto i:words) cout<<i<<" ";
        vector<int> dp(words.size(), 1);
        int len=1;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<=i-1;j++){
                if(compare(words[i], words[j]) && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                    len=max(len, dp[i]);
                }
            }
        }
        return len;
    }
};