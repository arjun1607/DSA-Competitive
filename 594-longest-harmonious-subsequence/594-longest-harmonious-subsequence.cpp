class Solution {
public:
    int findLHS(vector<int>& nums){
        unordered_map<int,int> m; for(int i:nums) m[i]++;
        int maxx=*max_element(nums.begin(), nums.end());
        int ans=0;
        for(int i:nums){
            if(i!=maxx && m[i]>0 && m[i+1]>0) ans=max(ans, m[i]+m[i+1]);
        }
        return ans;
    }
};