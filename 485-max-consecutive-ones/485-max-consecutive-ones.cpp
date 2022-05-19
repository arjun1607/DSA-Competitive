class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0, temp=0;
        for(int i:nums){
            if(i==0) temp=0;
            else temp++;
            ans=max(ans, temp);
        }
        return ans;
    }
};