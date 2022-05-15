class Solution {
public:
    bool vowel(char c){
        if(c=='a'||
          c=='e'||
          c=='i'||
          c=='o'||
           c=='u'||
           c=='A'||
          c=='E'||
          c=='I'||
          c=='O'||
          c=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(!vowel(s[i])) i++;
            if(!vowel(s[j])) j--;  
            if(vowel(s[i]) && vowel(s[j])){
                swap(s[i], s[j]);
                i++; j--;
            }
        }
        return s;
    }
};