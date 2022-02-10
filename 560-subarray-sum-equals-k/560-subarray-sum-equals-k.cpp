class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1, 0);
        for(int i=0;i<nums.size();i++) pre[i+1]=pre[i]+nums[i];
        unordered_map<int, int> m; int c=0;
        for(int i:pre){
            if(m.find(i-k)!=m.end()) c+=m[i-k];
            m[i]++;
        }
        return c;
    }
};

// x-y=k
// y=x-k