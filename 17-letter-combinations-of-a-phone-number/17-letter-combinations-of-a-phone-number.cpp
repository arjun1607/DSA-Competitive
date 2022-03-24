class Solution {
public:
    vector<string> codes = { "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
    vector<string> help(string d){
        if(d.size()==0) return {""};
        char ch=d[0];
        string ros=d.substr(1);
        string codesforch=codes[ch-'1'];
        vector<string> recans=help(ros), myans;
        for(char c:codesforch){
            for(string s:recans){
                myans.push_back(c+s);
            }
        }
        return myans;
    }
    vector<string> letterCombinations(string d) {
        if(d=="") return {};
        else return help(d);
    }
};