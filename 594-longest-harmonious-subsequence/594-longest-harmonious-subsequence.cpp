class Solution {
public:
    int findLHS(vector<int>& nums){
        /*
        unordered_map<int,int> m; for(int i:nums) m[i]++;
        int maxx=*max_element(nums.begin(), nums.end());
        int ans=0;
        for(int i:nums){
            if(i!=maxx && m[i]>0 && m[i+1]>0) ans=max(ans, m[i]+m[i+1]);
        }
        return ans;
        */
        // 1 22333 455667
        sort(nums.begin(), nums.end());
        int i=0, j=0, ans=0;
        while(j<nums.size()){
            if(nums[j]-nums[i]==0) j++;
            else if(nums[j]-nums[i]==1){
                ans=max(ans, j-i+1);
                j++;
            }else if(nums[j]-nums[i]>1){
                while(nums[j]-nums[i]>1){
                    i++;
                }
            }
        }
        return ans;
    }
};