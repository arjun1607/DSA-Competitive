class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> a, b;
        for(char c:s){
            if(c=='#' && !a.empty()) a.pop();
            else if(c!='#') a.push(c);
        }
        for(char c:t){
            if(c=='#' && !b.empty()) b.pop();
            else if(c!='#') b.push(c);
        }
        return a==b;
    }
};