class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int> lps(n);
        lps[0]=0;
        int i=1, j=lps[i-1];
        while(i<n){
            if(s[i]==s[j]){
                lps[i]=j+1;
                j++;
                i++;
            }else {
                if(j==0){
                    lps[i]=0;
                    i++;
                }else j=lps[j-1];
            }
        }
        return lps[n-1]!=0 && n%(n-lps[n-1])==0 ;       
    }
};