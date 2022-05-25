class Solution {
public:
    string minRemoveToMakeValid(string str) {
        stack<int> s;
        for(int i=0;i<str.size();i++){
            if(str[i]=='(') s.push(i);
            else if(str[i]==')'){
                if(!s.empty()) s.pop();
                else str[i]='#';
            }
        }
        while(!s.empty()){
            str[s.top()]='#';
            s.pop();
        }
        string ans="";
        for(char &c:str){
            if(c!='#') ans+=c;
        }
        return ans;
    }
};