class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int i=0, k=1, jumps=0;
        while(i<target){
            i+=k; k++; jumps++;
        }
        if(i==target) return jumps;
        else{
                while(true){
                    int diff=i-target;
                    if(diff%2==0) return  jumps;
                    i+=k; k++; jumps++;        
                }
        }
    }
};