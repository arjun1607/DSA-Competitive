class Solution {
public:
    string reverseParentheses(string str) {
        stack<char> s;
        for(char c:str){
            if(c!=')') s.push(c);
            else{
                string t="";
                while(s.top()!='('){
                    t+=s.top();
                    s.pop();
                }
                s.pop();
                for(char ch:t) s.push(ch);
            }
        }
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};