class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /*
        int i=0, j=0, zeros=0, ans=0;
        while(j<nums.size()){
            if(nums[j]==0) zeros++;
            if(zeros<=k){
                ans=max(ans, j-i+1);
            }else if(zeros>k){
                while(zeros>k){
                    if(nums[i]==0) zeros--;
                    i++;
                }
            }
            j++;
        }
        return ans;
        */
        int i=0, j=0, ans=0;
        deque<int> l;
        while(j<nums.size()){
            if(nums[j]==0) l.push_back(j);
            if(l.size()<=k){
                ans=max(ans, j-i+1);
            }else if(l.size()>k){
                i=l.front()+1;
                l.pop_front();
            }
            j++;
        }
        return ans;
    }
};





