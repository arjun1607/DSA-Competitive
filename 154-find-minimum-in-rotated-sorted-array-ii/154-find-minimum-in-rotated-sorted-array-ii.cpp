class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int s=0, e=n-1;
        while(s<e){
            int m=s+(e-s)/2;
            if(nums[m]>nums[e])
                s=m+1;
            else if(nums[m]<nums[s])
                e=m;
            else 
                e--;
        }
        return nums[s];
    }
};