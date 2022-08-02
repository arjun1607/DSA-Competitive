class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        stack<int> s;
        while(j<popped.size()){
            if(!s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }
            else if(i<pushed.size()){
                s.push(pushed[i]);
                i++;
            }
            else return false;
        }
        return true;
    }
};