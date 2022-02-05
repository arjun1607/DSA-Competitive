class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int c=0;
        bool word=false;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && word==true) break;
            if(isalpha(s[i])){
                word=true;
                c++;
            }
        }
        return c;
    }
};