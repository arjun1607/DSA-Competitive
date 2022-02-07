class Solution {
public:
    int helper(vector<int> &nums, int k){
        // SLIDING WINDOW
        unordered_map<int,int> m;
        int i=0, j=0, ans=0;
        while(j<nums.size()){
            m[nums[j]]++;
            if(m.size()<=k){
                ans+=(j-i+1);
                j++;
            }else if(m.size() > k){  
                while(m.size() > k){
                    m[nums[i]]--;
                    if(m[nums[i]]==0) m.erase(nums[i]);
                    i++;
                }
                ans+=(j-i+1);
                j++;
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k)-helper(nums, k-1);
    }
};