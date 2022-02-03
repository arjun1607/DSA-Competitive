class Solution {
public:
    int maxScore(string s) {
        vector<int> pre(s.size()+1, 0);
        for(int i=s.size()-1;i>=0;i--){
            pre[i]=(s[i]=='1')?pre[i+1]+1:pre[i+1];
        }
        int count=(s[0]=='0')?1:0;
        int ans=0;
        for(int i=1;i<s.size();i++){
            ans=max(ans, count+pre[i]);
            if(s[i]=='0') count++;
        }
        return ans;
    }
};