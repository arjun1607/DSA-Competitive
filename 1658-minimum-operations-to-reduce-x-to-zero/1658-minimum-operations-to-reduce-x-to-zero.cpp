class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=0;
        for(int i:nums) s+=i;
        x=s-x;

        // now finding max subarray whose sum is x
        int i=0, j=0, size=-1, sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum==x){
                size=max(size, j-i+1);
            }else if(sum>x){
                while(sum>x && i<nums.size()){
                    sum-=nums[i];
                    i++;
                }
                if(sum==x) size=max(size, j-i+1);
            }
            j++;
        }
        
        if(size==-1) return -1;    
        return nums.size()-size;
    }
};