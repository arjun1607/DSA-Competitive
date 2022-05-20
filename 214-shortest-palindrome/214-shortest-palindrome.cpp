class Solution {
public:
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(), t.end());
        t=s+'#'+t;
        vector<int> lps(t.size());
        lps[0]=0;
        int i=1, j=lps[i-1];
        cout<<t;
        while(i<t.size()){
            if(t[i]==t[j]){
                lps[i]=j+1;
                j++;
                i++;
            }else{
                if(j==0){
                    lps[i]=0;
                    i++;
                }else j=lps[j-1];
            }
        }
        int l=lps.back();
        t=s.substr(l);
        reverse(t.begin(), t.end());
        s=t+s;
        return s;
    }
};