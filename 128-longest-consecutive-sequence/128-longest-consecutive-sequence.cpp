class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxi=0;
        for(int i:nums){
            if(m.find(i)==m.end()){
                m[i]=1;
                int sp=i, ep=i;
                if(m.find(i-1)!=m.end()){
                    sp = i - m[i-1];
                }
                if(m.find(i+1)!=m.end()){
                    ep = i + m[i+1];
                }
                int len = ep - sp + 1;
                m[sp] = len;
                m[ep] = len;
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};