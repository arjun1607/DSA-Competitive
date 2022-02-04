class Solution {
public:
    int balancedStringSplit(string s) {
        // BALANCE VARIABLE TRICK
        int val=0, count=0;
        for(char c:s){
            if(c=='L') val++;
            else if(c=='R') val--;
            if(val==0) count++;
        }
        return count;
    }
};