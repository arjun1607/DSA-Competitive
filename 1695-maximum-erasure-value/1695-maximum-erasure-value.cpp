class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> m;
        int i=0, j=0, sum=0, ans=0;
        while(j<nums.size()){
            sum+=nums[j];
            m[nums[j]]++;        
            if(j-i+1==m.size()){
                ans=max(ans, sum);
            }else if(j-i+1 > m.size()){
                while(j-i+1 > m.size()){
                    sum-=nums[i];
                    m[nums[i]]--;
                    if(m[nums[i]]==0) m.erase(nums[i]);
                    i++;
                }
            }
            
            j++;
        }
        return ans;
    }
};