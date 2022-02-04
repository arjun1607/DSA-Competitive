class Solution {
public:
    string interpret(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='G') ans+='G';
            else if(s[i]=='(' && s[i+1]==')') ans+='o';
            else if(s[i]=='(' && s[i+1]=='a') ans+="al";
        }
        return ans;
    }
};