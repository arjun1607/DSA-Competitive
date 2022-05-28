typedef long long ll;
class MinStack {
public:
    MinStack() {
        
    }
    
    stack<ll> s;
    ll mini;
    
    void push(int val) {
        if(s.empty()){
            mini=val;
            s.push(0);
        }else{
            s.push(val-mini);
            if(val<mini) mini=val;
        }
    }
    
    void pop() {
        if(s.top()<0) mini=mini-s.top();
        s.pop();
    }
    
    int top() {
        if(s.top()<0) return mini;
        else return s.top()+mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */