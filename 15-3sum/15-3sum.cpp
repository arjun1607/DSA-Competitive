class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i=0, n=nums.size();
        while(i<n-2){
            int a=nums[i];
            int lo=i+1, hi=n-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]==-a){
                    ans.push_back({a, nums[lo], nums[hi]});
                    while(lo+1<n && nums[lo+1]==nums[lo]) lo++;
                    while(hi-1>=0 && nums[hi-1]==nums[hi]) hi--;
                    lo++; hi--;
                }
                else if(nums[lo]+nums[hi]<-a){
                    while(lo+1<n && nums[lo+1]==nums[lo]) lo++;
                    lo++;
                }else{
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