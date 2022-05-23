class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        s.push(pushed[0]);
        int i=1, j=0;
        while(j<popped.size()){
            if(!s.empty() && popped[j]==s.top()){
                s.pop();
                j++;
            }else if(i<pushed.size()){
                s.push(pushed[i]);
                i++;
            }else return false;
        }
        return true;
    }
};