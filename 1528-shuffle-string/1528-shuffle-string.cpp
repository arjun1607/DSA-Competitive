class Solution {
public:
    string restoreString(string s, vector<int>& idx) {
        int i=0;
        while(i<s.size()){
            if(idx[i]!=i){
                swap(s[i], s[idx[i]]);
                swap(idx[i], idx[idx[i]]);
            }else i++;
        }
        return s;
    }
};