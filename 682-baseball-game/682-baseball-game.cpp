class Solution {
public:
    int calPoints(vector<string>& ops) {
       stack<int> ss;
        for(auto s:ops){
          
         if(s=="+") {
                int x=ss.top();
                ss.pop();
                int y=ss.top();
                ss.push(x);
                ss.push(x+y);
            }else if(s=="D"){
                ss.push(2*ss.top());
            }else if(s=="C") ss.pop();
            else ss.push(stoi(s));
        }
        int ans=0;
        while(!ss.empty()){
            ans+=ss.top();
            ss.pop();
        }
        return ans;
    }
};