class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i:nums){
            if(k==0){
                if(m.find(i)!=m.end() && m[i]==1) ans++;
            }else{
                if(m.find(i)!=m.end()) continue;            
                if(m.find(i+k)!=m.end()) ans++;
                if(m.find(i-k)!=m.end()) ans++;
            }
            m[i]++;
        }
        
        return ans;
    }
};