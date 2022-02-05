class Solution {
public:
    int isPrefixOfWord(string s, string t) {
        int j=0, count=0;
        for(int i=0;i<s.size();){
            if(s[i]!=' '){
                if(s[i]==t[j]) { i++; j++; }
                else{
                    while(i<s.size() && s[i]!=' ') i++;
                }
                if(j==t.size()) return count+1;
            }else {
                count++;
                i++;
                j=0;
            }
        }
        return -1;
    }
};