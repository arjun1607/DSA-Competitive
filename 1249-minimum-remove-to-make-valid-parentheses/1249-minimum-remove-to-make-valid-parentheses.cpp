class Solution {
public:
    string minRemoveToMakeValid(string str) {
        /*
        int cnt=0;
        stack<pair<char, int>> s;
        for(char c:str){
            if(c=='('){
                cnt++;
                s.push({'(', cnt});
            }else if(c==')'){
                cnt++;
                if(!s.empty() && s.top().first=='(') s.pop();
                else s.push({')', cnt});
            }
        }

        string ans="";
        int cnt2=0;
        for(int i=str.size()-1; i>=0; i--){
            if(str[i]=='(' || str[i]==')'){
                cnt2++;
                if(!s.empty() && s.top().first==str[i] 
                      && cnt-s.top().second+1==cnt2) {
                    s.pop();
                    continue;
                }
                else ans+=str[i];
 
            }else ans+=str[i];
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
        */
        stack<char> s;
        for(char &c:str){
            if(c=='(') s.push(c);
            else if(c==')'){
                if(!s.empty() && s.top()=='(') s.pop();
                else c='*';
            }
        }
        string ans="";
        reverse(str.begin(), str.end());
        for(char c:str){
            if(c!='*') {
                if(!s.empty() && c==s.top()) s.pop();
                else ans+=c;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};