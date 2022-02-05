class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans(s.size()+1, -1);
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I') ans[i]=x++;
        }
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]==-1) ans[i]=x++;
        }
        return ans;
    }
};