class Solution {
public:
    bool checkIfPangram(string s) {
        int seen=0;
        for(char c:s){
            int n=c-'a';
            seen=seen|(1<<n);
        }
        return seen==((1<<26)-1);
    }
};