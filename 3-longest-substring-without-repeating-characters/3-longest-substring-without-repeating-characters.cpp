class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int i=0,j=0;
        int ans=0;
        while(j<s.size()){
            m[s[j]]++;
            if(j-i+1<m.size()) j++;
            else if(j-i+1==m.size()){
                ans=max(ans, j-i+1);
                j++;
            }
            else if(j-i+1>m.size()){
                while(j-i+1>m.size()){
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