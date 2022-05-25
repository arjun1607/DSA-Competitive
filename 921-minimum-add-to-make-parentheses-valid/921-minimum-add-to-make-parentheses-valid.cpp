class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<char> s;
        // stack only contain '('
        int ans=0;
        for(char &c:str){
            if(c=='(') s.push(c);
            else{
                if(!s.empty()) s.pop();
                else ans++;
            }
        }
        ans+=s.size();
        return ans;
    }
};