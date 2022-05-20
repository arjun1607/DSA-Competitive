class Solution {
public:
    string longestPrefix(string s) {
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
        string ans=s.substr(0, lps[s.size()-1]);
        return ans;
    }
};