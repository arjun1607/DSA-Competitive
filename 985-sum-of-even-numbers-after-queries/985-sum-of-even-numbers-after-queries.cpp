class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int sum=0;
        for(int i:nums){
            if(i%2==0) sum+=i;
        }
        vector<int> ans;
        for(auto i:q){
            int idx = i[1], val = i[0];
            if(nums[idx]%2==0){
                sum -= nums[idx];
                nums[idx] += val;
                if(nums[idx]%2==0 ) sum+=nums[idx];
                ans.push_back(sum);
            }
            else{
                nums[idx] += val;
                if(nums[idx]%2==0 ) sum+=nums[idx];
                ans.push_back(sum);
            }
        }
        return ans;
    }
};