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
            sum -= val;    
            if(sum>=val || sum<1) return false;
            
            long old=val%sum;
            
            sum += old;
            pq.pop();
            pq.push(old>0?old:sum);
        }
        return true;
    }
};