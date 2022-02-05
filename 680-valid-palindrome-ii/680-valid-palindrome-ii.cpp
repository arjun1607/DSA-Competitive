class Solution {
public:
    bool validPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<=j;i++,j--){
            if(s[i]!=s[j]){
                int p=i+1, q=j, u=i, v=j-1;
                while(p<=q && s[p]==s[q]){p++; q--;}
                while(u<=v && s[u]==s[v]){u++; v--;}
                if(p>q || u>v) return true;
                else if(p<q && u<v) return false;
            }
        }
        return true;
    }
};





