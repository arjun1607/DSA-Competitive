class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
    //    for(int i:nums) cout<<i<<" ";
        int ans=-1001;
        int i=0, n=nums.size();
        while(i<n-2){
            int a=nums[i];
            int lo=i+1, hi=n-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]+a==target){
                    return target;
                }
                else if(nums[lo]+nums[hi]+a < target){
                    int currsum = nums[lo]+nums[hi]+a;
                    if(target-currsum < abs(ans-target)) ans=currsum;
                    
                    while(lo+1<n && nums[lo+1]==nums[lo]) lo++;
                    lo++;
                }else if(nums[lo]+nums[hi]+a > target){
                    int currsum = nums[lo]+nums[hi]+a;
                    if(currsum-target < abs(ans-target)) ans=currsum;
                    
                    while(hi-1>=0 && nums[hi-1]==nums[hi]) hi--;
                    hi--;
                }
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
            i++;
        }
        return ans;
    }
};