class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int size=nums.size();
        vector<int> output(size);
        while(i<=j){
            if(pow(nums[i],2) > pow(nums[j],2)){
                output[--size]=pow(nums[i],2);
                i++;
            }else{
                output[--size]=pow(nums[j],2);
                j--;
            }
        }
        return output;
    }
};