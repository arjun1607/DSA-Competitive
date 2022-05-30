class Solution {
public:
    long operate(long val1, long val2, char op){
        if(op=='+') return val1+val2;
        else if(op=='-') return val1-val2;
        else if(op=='*') return val1*val2;
        else return val1/val2;
    }
    int calculate(string s) {
        if(s[0]=='-') s = '0' + s;
        unordered_map<char, int> prec;
        prec['+']=1;
        prec['-']=1;
        prec['*']=2;
        prec['/']=2;
        prec['(']=0;
        prec[')']=0;
        
        stack<long> nums;
        stack<char> opr; 
        
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            }
            
            if(isdigit(s[i])){
                long val=0;
                while(i<s.size() && isdigit(s[i])){
                    val = val*10 + (s[i]-'0');
                    i++;
                }
                nums.push(val);
            }
            else if(s[i]=='('){
                if(s[i+1]=='-') s.insert(i+1, "0");
                opr.push('(');
                i++;
            }
            else if(s[i]==')'){
                while(opr.top()!='('){
                    long val2 = nums.top(); nums.pop();
                    long val1 = nums.top(); nums.pop();
                    char op = opr.top(); opr.pop();
                    long ans = operate(val1, val2, op);
                    nums.push(ans);
                }
                
                opr.pop();
                i++;
            }
            else{
                while(!opr.empty() && prec[s[i]] <= prec[opr.top()]){
                    long val2 = nums.top(); nums.pop();
                    long val1 = nums.top(); nums.pop();
                    char op = opr.top(); opr.pop();
                    long ans = operate(val1, val2, op);
                    nums.push(ans);
                }
                
                opr.push(s[i]);
                i++;
            }
        }
        
        // possibly some operator remain in stack 
        // Ex, s = 3+4 + (8/4)
        while(!opr.empty() && prec[s[i]] <= prec[opr.top()]){
            long val2 = nums.top(); nums.pop();
            long val1 = nums.top(); nums.pop();
            char op = opr.top(); opr.pop();
            long ans = operate(val1, val2, op);
            nums.push(ans);
        }
               
        long ans = nums.top();
        return (int)ans;
    }
};


































