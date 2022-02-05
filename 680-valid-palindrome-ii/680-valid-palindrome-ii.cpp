class Solution {
public:
    bool validPalindrome(string s) {
        /*
        Check from left and right at the same time until the first different pair.
Now we have something like a****b, where a and b are different.
We need to delete either a or b to make it a palindrome.
        */
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            if(s[i]!=s[j]){
                int p=i,q=j-1,u=i+1,v=j;
                while(p<q && s[p]==s[q]){p++; q--;}
                while(u<v && s[u]==s[v]){u++; v--;}
                return p>=q || u>=v;
            }
        }
        return true;
    }
};