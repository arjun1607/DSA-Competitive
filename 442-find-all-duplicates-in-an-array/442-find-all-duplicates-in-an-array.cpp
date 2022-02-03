class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*
        we Can Use -[minus] To track Each Element we are traverse Or Not [as They said That any element can occoure max Twice]
While Traverseing if We Get Negetive element again We Know That It's Allredy Visited So It Wolud Be a duplicate num <= Push That Into ANS array
        */
        vector<int> ans;
        for(int i:nums){
            if(nums[abs(i)-1]<0) ans.push_back(abs(i));
            else nums[abs(i)-1] = -abs(nums[abs(i)-1]);
        }
        return ans;
    }
};