class Solution {
public:
    bool checkString(string s) {
        int b=0;
        for(char c:s){
            if(c=='b'){
                b=1;
            }else if(c=='a' && b==1) return false;
        }
        return true;
    }
};