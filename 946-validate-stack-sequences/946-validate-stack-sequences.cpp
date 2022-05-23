class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0, j=0;
        while(j<popped.size()){
            // popped array ko preference deni hogi 
            // push to always hi kr sakte h
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