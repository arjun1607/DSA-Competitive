class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,1), dp2(n,1);
        for(int i=1;i<n;i++)
            if(nums[i]>nums[i-1])
                dp1[i]=dp1[i-1]+1;           
        
        for(int i:dp1) cout<<i<<" ";
        cout<<endl;
        
        for(int i=n-2;i>=0;i--)
            if(nums[i]>nums[i+1])
                dp2[i]=dp2[i+1]+1; 
        
        for(int i:dp2) cout<<i<<" ";
        
        int lbs=0;
        for(int i=1;i<n-1;i++)
            if(dp1[i]>1 && dp2[i]>1)
                lbs=max(lbs, dp1[i]+dp2[i]-1);
        
        return lbs;
    }
};