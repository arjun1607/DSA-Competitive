class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> preMax(n), sufMax(n);
        preMax[0]=nums[0];
        sufMax[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            if(i%k==0) preMax[i]=nums[i];
            else preMax[i]=max(preMax[i-1], nums[i]);
        }
        for(int j=n-2;j>=0;j--){
            if((j+1)%k==0) sufMax[j]=nums[j];
            else sufMax[j]=max(sufMax[j+1], nums[j]);     
        }
        vector<int> ans(n-k+1);
        for(int i=0;i<=n-k;i++){
            if(i%k==0) ans[i]=sufMax[i];
            else ans[i]=max(sufMax[i], preMax[i+k-1]);
        }
        return ans;
    }
};