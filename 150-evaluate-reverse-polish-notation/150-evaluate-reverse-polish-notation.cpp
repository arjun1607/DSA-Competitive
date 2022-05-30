class Solution {    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]== "+"|| tokens[i]=="-" ||  tokens[i]=="*" || tokens[i]=="/"){
                int val2=s.top(); s.pop();
                int val1=s.top(); s.pop();
                if(tokens[i]== "+") s.push(val1 + val2);  
                if(tokens[i]== "-") s.push(val1 - val2); 
                if(tokens[i]== "*") s.push(val1 * val2);
                if(tokens[i]== "/") s.push(val1 / val2);
            }
            else s.push(stoi(tokens[i]));  
        }
        return s.top();
    }
};