class Solution {
public:
    string removeDuplicates(string s) {
        /*
        stack<char> st;
        for(char c:s){
            if(!st.empty() && st.top()==c) st.pop();
            else st.push(c);
        }
        string ans=""; 
        while(!st.empty()){
            ans+=st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        */
        int i=0;
        for(int j=1;j<s.size();j++){
            if(i>=0 && s[j]==s[i]){
                i--;
            }else{
                s[++i]=s[j];
            }
        }
        return s.substr(0, i+1);
    }
};