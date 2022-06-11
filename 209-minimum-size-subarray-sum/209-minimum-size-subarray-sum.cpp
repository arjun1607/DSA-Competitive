class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, ans=INT_MAX, sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum>=target){
                ans=min(ans, j-i+1);
                cout<<i<<" "<<j<<" "<<sum<<endl;
                while(sum>=target && i<nums.size()){
                    sum-=nums[i];
                    i++;
                    cout<<"here "<< i<<" "<<j<<" "<<sum<<endl;
                    if(sum>=target) ans=min(ans, j-i+1);
                }
            }
            j++;
        }
        return (ans==INT_MAX)?0:ans;
    }
};