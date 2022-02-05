class Solution {
public:
    int numOfStrings(vector<string>& p, string s) {
        int ans=0;
        for(auto i:p){
            if(s.find(i)!=string::npos) ans++;
        }
        return ans;
    }
};