class Solution {
public:
    int maxRepeating(string s, string t) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int k=i, cnt=0;
            while(k<s.size() && s.substr(k, t.size())==t){
                cnt++;
                k+=t.size();
            }
            ans=max(ans, cnt);
        }
        return ans;
    }
};