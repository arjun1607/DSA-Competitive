class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixprod=1, overall=INT_MIN;
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            prefixprod*=nums[i];
            overall = max(overall, prefixprod);
            if(nums[i]==0){
                flag=true;
                prefixprod=1;
            }
        }
        int suffixprod=1;
        for(int j=nums.size()-1;j>=0;j--){
            suffixprod*=nums[j];
            overall = max(overall, suffixprod);
            if(nums[j]==0){
                flag=true;
                suffixprod=1;
            }
        }
        if(flag) overall =max(overall, 0);
        return overall;
    }
};