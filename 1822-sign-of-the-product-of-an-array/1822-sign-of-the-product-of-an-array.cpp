class Solution {
public:
    int arraySign(vector<int>& nums) {
        int c0=0, cn=0;
        for(int i:nums){
            if(i==0) c0++;
            else if(i<0) cn++;
        }
        if(c0>0) return 0;
        else if(cn%2==1) return -1;
        else return 1;
    }
};