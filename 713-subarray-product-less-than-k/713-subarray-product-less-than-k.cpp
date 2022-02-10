class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i=0, j=0, p=1, c=0;
        while(j<nums.size()){
            p*=nums[j];
            if(p<k) c+=(j-i+1);
            else if(p>=k){
               while(p>=k){
                p/=nums[i];
                i++;
               }
                c+=(j-i+1);
            }
            j++;
        }
        return c;
    }
};