class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
       if(s.size()%k!=0) { string t(k-s.size()%k, fill); s+=t; }
        vector<string> v;
        int i=0; 
        while(i<s.size()){
            v.push_back(s.substr(i, k));
            i+=k;
        }
        return v;
    }
};