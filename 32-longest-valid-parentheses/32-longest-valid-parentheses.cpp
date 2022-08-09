class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        int maxi = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='(') s.push(i);
            else{
                if(!s.empty() && str[s.top()]=='('){
                    s.pop();
                    int val = s.empty() ? -1 : s.top();
                    maxi=max(maxi, i-val);
                }
                else s.push(i);
            }
        }
        return maxi;
    }
};