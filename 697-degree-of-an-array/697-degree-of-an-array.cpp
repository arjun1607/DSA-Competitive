class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> m; for(int i:nums) m[i]++;
        int f=INT_MIN; 
        vector<int> v;
        for(auto i:m){
            if(i.second > f){
                f=i.second;
                v.clear();
                v.push_back(i.first);
            }else if(i.second == f) v.push_back(i.first);
        }
        int ans=INT_MAX;
        for(int val:v){
            int i=0,j=0; bool first=false;
            for(int k=0;k<nums.size();k++){
                if(nums[k]==val){
                    j=k;
                    if(first==false){
                        i=k; first=true;
                    }
                }
            }
            ans=min(ans,j-i+1);
        }
        return ans;
    }
};