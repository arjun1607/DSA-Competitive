class Solution {
public:
    vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
        "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        for(auto i:words){
            string temp = "";
            for(char c:i){
                temp += m[c-'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};