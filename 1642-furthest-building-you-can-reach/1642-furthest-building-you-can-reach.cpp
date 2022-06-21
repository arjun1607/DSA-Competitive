class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        // greedy approach :- use ladders for longer climbs & bricks for shorter ones
        // we need a datastructure to hold k largest climbs (k = no of ladders)
        // iterate and store the heights to climb in DS of size k
        // when new height to climb comes , we will check if we can optimise the resources by using ladder tp climb current height instead of which we climbed in past
        
        // if current height to climb > one of the heights in k highest climbs
        // thus try swapping ladder with bricks for lower height
        // if possible replace ladder with bricks and store current height to climb in DS and climb further else cannot go any further
        
        // the DS we'll use is MIN HEAP
        int n=h.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1;i<n;i++){
            int diff = h[i]-h[i-1];
            if(diff > 0){
                if(pq.size() < ladders){
                    pq.push(diff);
                }else{
                    int br = diff;
                    
                    // optimise previous ladder use
                    if(!pq.empty() && pq.top()<diff){
                        br = pq.top();
                        pq.pop();
                        pq.push(diff);
                    }
                    
                    bricks -= br;
                    if(bricks < 0){
                        return i-1;
                    }
                }
            }
        }
        return n-1;
    }
};