class Solution {
public:
    int maxPower(string s) {
        unordered_map<char, int> m;
        int i=0, j=0;
        int ans=0;
        while(j<s.size()){
            m[s[j]]++;
            if(m.size()==1){
                ans=max(ans, j-i+1);
                j++;
            }else if(m.size()>1){
                while(m.size()>1){
                    m[s[i]]--;
                    if(m[s[i]]==0) m.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};