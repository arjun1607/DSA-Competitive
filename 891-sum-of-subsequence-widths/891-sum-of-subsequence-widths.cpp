
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long sum=0, mod=1e9+7;
        long *pow = new long[nums.size()];
        pow[0]=1;
        for(int i=1;i<nums.size();i++){
            pow[i]=pow[i-1]*2 % mod;
        }
        for(int i=0;i<nums.size();i++)
            sum = ( sum + (pow[i]-pow[nums.size()-i-1])*nums[i] )%mod;
        return sum;
    }
};