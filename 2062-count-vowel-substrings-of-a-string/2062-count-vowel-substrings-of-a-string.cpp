class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int helper(string s, int k){
        unordered_map<char,int> m;
        int i=0, j=0, ans=0;
        while(j<s.size()){
            if(!isVowel(s[j])){
                i=j+1;
                m.clear();
            }else m[s[j]]++;
            
            if(m.size()<=k) ans+=(j-i+1);
            else if(m.size()>k){
                while(m.size()>k){
                    m[s[i]]--;
                    if(m[s[i]]==0) m.erase(s[i]);
                    i++;
                }
                ans+=(j-i+1);
            }
            
            j++;
        }
        return ans;
    }
    int countVowelSubstrings(string s) {
        return helper(s, 5) - helper(s, 4);
    }
};

























