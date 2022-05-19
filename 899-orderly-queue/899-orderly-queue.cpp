class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>=2){
            sort(s.begin(), s.end()); 
            return s;
        }
        string ans=s;
        for(int i=0;i<s.size();i++){
            char c=s[0];
            s=s.substr(1)+c;
            ans=min(ans, s);
        }
        return ans;
    }
};