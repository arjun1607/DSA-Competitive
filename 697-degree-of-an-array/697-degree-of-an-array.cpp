class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> m; 
        for(int i=0;i<nums.size();i++) m[nums[i]].push_back(i);
        int f=0; 
        vector<int> v;
        for(auto i:m){
            if(i.second.size() > f){
                f=i.second.size();
                v.clear();
                v.push_back(i.first);
            }else if(i.second.size() == f) v.push_back(i.first);
        }      
        int ans=INT_MAX;
        for(int val:v){
            cout<<val<<" ";
            ans=min(ans,m[val].back()-m[val].front()+1);
        }
        return ans;
    }
};