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
            
            long old=val%restsum; // to reduce time complexity
            // suppose s
            
            sum = restsum + old;
            pq.pop();
            pq.push(old>0?old:sum);
        }
        return true;
    }
};