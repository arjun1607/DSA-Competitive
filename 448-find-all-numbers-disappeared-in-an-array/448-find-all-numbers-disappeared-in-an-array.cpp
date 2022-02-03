class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {    
        /*
        // USING SPACE
        set<int> s; for(int i:nums) s.insert(i);
        vector<int> ans;
        for(int i=1;i<=nums.size();i++){
            if(s.find(i)==s.end()) ans.push_back(i);
        }
        return ans;
        */
        
        // USING SWAP SORT
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};