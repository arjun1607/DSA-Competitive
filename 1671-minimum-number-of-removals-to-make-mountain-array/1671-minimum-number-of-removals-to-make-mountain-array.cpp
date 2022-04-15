class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,1), dp2(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j]<nums[i] && dp1[j]+1>dp1[i])
                    dp1[i]=dp1[j]+1;
            }
        }
        for(int i:dp1) cout<<i<<" ";
        cout<<endl;
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=i+1;j--){
                if(nums[j]<nums[i] && dp2[j]+1>dp2[i])
                    dp2[i]=dp2[j]+1;
            }
        }
        for(int i:dp2) cout<<i<<" ";
        int lbs=0;
        for(int i=1;i<n-1;i++)
            if(dp1[i]>1 && dp2[i]>1)
                lbs=max(lbs, dp1[i]+dp2[i]-1);
        
        return n-lbs;
    }
};