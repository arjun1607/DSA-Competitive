class Solution {
public:
    bool check(string text, string ptr){
        string s=ptr+'#'+text;
        vector<int> lps(s.size(), 0);
        int i=1, j=lps[i-1]; 
        while(i<s.size()){
            if(s[i]==s[j]){
                lps[i]=j+1;
                j++;
                i++;
            }else{
                if(j==0) {
                    lps[i]=0;
                    i++;
                }
                else j=lps[j-1];
            }
        }
        for(int val:lps) if(val==ptr.size()) return true;
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n=ceil(b.size()*1.0/a.size());
        string text=a;
        for(int i=1;i<n;i++) text+=a;
        if(check(text, b)) return n;
        else {
            text+=a;
            if(check(text, b)) return n+1;
        }
        return -1;
    }
};












