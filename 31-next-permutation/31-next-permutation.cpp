class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx1=n-2;
        while(idx1>=0){
            if(nums[idx1] < nums[idx1+1]) break;
            idx1--;
        }
        cout<<idx1<<endl;
        if(idx1!=-1){
            int idx2=n-1;
            while(idx2>idx1){
                if(nums[idx2]>nums[idx1]) break;
                idx2--;
            }
            cout<<idx2<<endl;
            swap(nums[idx1], nums[idx2]);
        }
        for(int i:nums) cout<<i<<" ";
        reverse(nums.begin()+idx1+1, nums.end());
    }
};