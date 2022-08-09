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
        // optimal approach is to balance 2 sets of brackets at a time using 1 swap
        // desi bhasha -  1 swap 4 bando ko le dubega
        return ceil(s.size()/4.0);
    }
};