class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0, e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int prev=(mid-1+n)%n;
            int front=(mid+1)%n;
            if(nums[mid]<nums[prev] && nums[mid]<nums[front]) return nums[mid];
            if(nums[mid]<=nums[e]) e=mid-1;
            else if(nums[s]<=nums[mid]) s=mid+1;
        }
        return nums[0];
    }
};