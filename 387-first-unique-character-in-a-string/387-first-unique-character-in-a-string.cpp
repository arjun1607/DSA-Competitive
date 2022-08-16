class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(char c:s){
            m[c]++;
        }
        int ans=-1;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};