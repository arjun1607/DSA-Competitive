class Solution {
public:
    bool check(vector<int> &v){
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]) return false;
        }
        return true;
    }
    bool canBeIncreasing(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int t=nums[i];
            nums[i]=0;
            vector<int> v; for(int j:nums) if(j!=0) v.push_back(j);
            if(check(v)) return true;
            nums[i]=t;
        }
        return false;
    }
};