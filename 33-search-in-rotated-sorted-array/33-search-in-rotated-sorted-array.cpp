class Solution {
public:
    int find(vector<int>& nums) {
        int n=nums.size();
        int s=0, e=n-1;
        while(s<e){
            int m=s+(e-s)/2;
            if(nums[m]>nums[e]) s=m+1;
            else e=m;
        }
        return s;
    }
    int search(vector<int>& nums, int k) {
        int i=find(nums);
        int ans=-1;
        cout<<i<<endl;
        if(i-1>=0 && binary_search(nums.begin(), nums.begin()+i, k)){
            ans=lower_bound(nums.begin(), nums.begin()+i, k)-nums.begin();
        }
        if(binary_search(nums.begin()+i, nums.end(), k)){
            ans=lower_bound(nums.begin()+i, nums.end(), k)-nums.begin();
        }
        return ans;
    }
};