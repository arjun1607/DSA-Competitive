class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        // stack will contain unpaired brackets
        int ans=0, i=0;
        while(i<str.size()){
            if(str[i]=='(') s.push(i);
            else{
                if(!s.empty() && str[s.top()]=='('){
                    s.pop();
                    int last_unpaired=s.empty()?-1:s.top();
                    ans=max(ans, i-last_unpaired);
                }
                else s.push(i);
            }
            i++;
        }
        return ans;
    }
};