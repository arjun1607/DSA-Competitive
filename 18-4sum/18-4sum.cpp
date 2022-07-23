class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i=0, n=nums.size();
        while(i<n-3){
            int j=i+1;
            while(j<n-2){
                int lo=j+1, hi=n-1;
                long remaining=k*1L-nums[i]-nums[j];
                while(lo<hi){
                    if(nums[lo]+nums[hi]==remaining){
                        ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        while(lo+1<n && nums[lo+1]==nums[lo]) lo++;
                        while(hi-1>=0 && nums[hi-1]==nums[hi]) hi--;
                        lo++, hi--;
                    }
                    else if(nums[lo]+nums[hi]<remaining){
                        while(lo+1<n && nums[lo+1]==nums[lo]) lo++;
                        lo++;
                    }
                    else{
                        while(hi-1>=0 && nums[hi-1]==nums[hi]) hi--;
                        hi--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
                j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
            i++;
        }
        return ans;
    }
};