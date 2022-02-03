class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m; for(char c:s) m[c]++;
        
        int ans=0;
        bool ifodd=false;
        for(auto i:m){
            if(i.second%2==0) ans+=i.second;
            else { ifodd=true; ans+=i.second-1; }
        }
        return (ifodd)?ans+1:ans;
    }
};