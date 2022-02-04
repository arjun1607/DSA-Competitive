class Solution {
public:
    int balancedStringSplit(string s) {
        vector<int> pre(s.size(),0);
        pre[0]=(s[0]=='L')?1:0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='L') pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
        }
        int c=0, ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R') c++;
            if(c==pre[i]) ans++;
        }
        return ans;
    }
};