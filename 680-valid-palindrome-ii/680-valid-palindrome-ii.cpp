class Solution {
public:
    bool validPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                bool ok1=true, ok2=true;
                for(int x=i, y=j-1;x<y;x++, y--) if(s[x]!=s[y]) ok1=false;
                for(int x=i+1, y=j;x<y;x++, y--) if(s[x]!=s[y]) ok2=false;
                if(!ok1 && !ok2) return false;
                break;
            }
            i++; j--;
        }
        return true;
    }
};