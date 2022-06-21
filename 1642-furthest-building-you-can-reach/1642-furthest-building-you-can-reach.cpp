class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        // greedy approach :- use ladders for longer climbs & bricks for shorter ones
        // we need a data structure to hold k largest climbs (k = no of ladders)
        // iterate and store the heights to climb in DS of size k
        // when new height to climb comes , we will check if we can optimise the resources by using ladder to climb current greater height instead of what smaller height we climbed in past
        
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
                    /*
                    If curJumpHeight > min-heap top : We have the choice to use bricks on the previous jump which had less jump height. So, we will use that many bricks on previous (smaller) jump and use ladder for current (larger) jump.

If curJumpHeight <= min-heap top : There's no way to minimize usage of bricks for current jump. We need to spend atleast curJumpHeight number of bricks
                    */
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