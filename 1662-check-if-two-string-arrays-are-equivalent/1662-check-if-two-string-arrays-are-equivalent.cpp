class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int p=0, q=0; // outer ptr
        int r=0, s=0; // inner ptr
        while(p<word1.size() && q<word2.size()){
            while(r<word1[p].size() && s<word2[q].size()){
                if(word1[p][r]!=word2[q][s]) return false;
                r++; s++;
            }
            if(r==word1[p].size()){
                p++;
                r=0;
            }
            if(s==word2[q].size()){
                q++;
                s=0;
            }
        }
        if(p!=word1.size() || q!=word2.size()) return false;
        else return true;
    }
};