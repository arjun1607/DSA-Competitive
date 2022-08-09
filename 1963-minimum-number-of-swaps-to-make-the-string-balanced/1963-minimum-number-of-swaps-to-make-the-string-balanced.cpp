class Solution {
public:
    int minSwaps(string str) {
        stack<char> s;
        int ans=0;
        for(char c:str){
            if(c==']'){
                if(!s.empty() && s.top()=='[') s.pop();
                else s.push(c);
            }
            else s.push(c);
        }
        return ceil(s.size()/4.0);
    }
};