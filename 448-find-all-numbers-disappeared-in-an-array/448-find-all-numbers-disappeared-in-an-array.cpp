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
        
        /*
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
        */
        
        /*
        nums[i] ki asli position pr jo betha h usko -ve kardo
        mark as present by negating
        
        We can iterate over nums and for each element, we know it can be mapped to index nums[i]-1. We can therefore             mark the element nums[i] as present in nums by making the element at index nums[i]-1 negative. Thus after               iterating the array, we have -

        nums[i] < 0 or nums[i] is negative only if the element i+1 is present in the array.
        nums[i] > 0 or nums[i] is positive only if the element i+1 is not present in the array
        */
        for(int i:nums){
           nums[abs(i)-1] = -abs(nums[abs(i)-1]);
        }    
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};

















