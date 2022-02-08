class Solution {
    private : 
    int MOD=1e9+7;
public:
    int numSub(string s) {
        long long i=0, j=0, ans=0;
        while(j<s.size()){
            if(s[j]=='0'){
                i=j+1;
            }else{
                ans+=(j-i+1);
            }
            j++;
        }
        return ans%MOD;
    }
};