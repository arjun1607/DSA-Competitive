class Solution {
public:
    void reverse(string &s, int i, int j){
        if(i>=j) return;
        while(i<=j){
            swap(s[i], s[j]);
            i++, j--;
        }
    }
    string reverseWords(string s) {
        int i=0, j=0;
        while(j<s.size()){
            if(s[j]==' '){
                reverse(s, i, j-1);
                i=j+1;
            }
            j++;
        }
        reverse(s, i, j-1);
        return s;
    }
};