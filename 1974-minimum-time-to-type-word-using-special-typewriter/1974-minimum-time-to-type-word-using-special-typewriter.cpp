class Solution {
public:
    int minTimeToType(string s) {
        s="a"+s;
        int ans=0;
        for(int i=1;i<s.size();i++){
            int t=(abs(s[i]-s[i-1]))%26;
            t=min(t, 26-t);
            ans+=(t+ 1);
        }
        return ans;
    }
};