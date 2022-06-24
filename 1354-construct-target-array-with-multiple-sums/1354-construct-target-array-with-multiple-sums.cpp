class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long> pq;
        long sum=0;
        for(int &i:target){
            pq.push((long)i);
            sum+=i;
        }      
        while(pq.top()!=1){
            long val=pq.top();
            long restsum = sum - val;    
            if(restsum>=val || restsum<1) return false;
            
            long old=val%restsum; // % to reduce time complexity
            // suppose val=1001, restsum=2
            // if we reduce 2 each time like 1001->999->997->......->1 this will take so much time
            // we can directly do %, and get 1001 -> 1 in one go
            
            sum = restsum + old;
            pq.pop();
            
            // suppose val=25, restsum=5
            // by doing %, we will get old = 0 but we should get 5 by eventually reducing 25->20->15->10->5
            pq.push(old>0?old:sum);
        }
        return true;
    }
};