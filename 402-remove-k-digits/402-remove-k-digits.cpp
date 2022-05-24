class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";
        stack<char> s;
        for(int i=0;i<num.size();i++){
            while(!s.empty() && num[i]<s.top() && k>0){
                s.pop();
                k--;
            }
            if(s.empty() && num[i]=='0') continue;
            s.push(num[i]);
        }
        
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return (ans.size()==0)?"0":ans;
    }
};