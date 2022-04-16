class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n=nums.size();
        /*
        vector<int> dp1(n,1), dp2(n,1);
        for(int i=1;i<n;i++)
            if(nums[i]>nums[i-1])
                dp1[i]=dp1[i-1]+1;           
        
        for(int i=n-2;i>=0;i--)
            if(nums[i]>nums[i+1])
                dp2[i]=dp2[i+1]+1; 
        
        int lbs=0;
        for(int i=1;i<n-1;i++)
            if(dp1[i]>1 && dp2[i]>1)
                lbs=max(lbs, dp1[i]+dp2[i]-1);
        
        return lbs;
        */
        int i=0, ans=0;
        while(i<n){
            int up=i+1;            
            while(up<n && nums[up]>nums[up-1]) up++;
            int down=up;
            while(down<n && nums[down]<nums[down-1]) down++;
            if(up-i>=2 && down-up>=1) ans=max(ans, down-i);        
            if(down<n && down-1>=0 && nums[down-1]<nums[down]) 
                i=down-1;
            else
                i=down;
        }
        return ans;
    }
};