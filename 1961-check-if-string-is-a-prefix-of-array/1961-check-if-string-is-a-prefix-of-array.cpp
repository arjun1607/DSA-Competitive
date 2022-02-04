class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i=0, j=0, k=0;
        while(i<s.size() && j<words.size()){
            k=0;
            while(k<words[j].size() && s[i]==words[j][k]){
                k++;
                i++;
            }
            if(k==0) return false;
            j++;
        }
        if(k!=words[j-1].size() || i!=s.size()) return false;
        return true;
    }
};