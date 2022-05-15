class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1=INT_MIN, m2, m3, s1=INT_MAX, s2;
        m2=m3=m1; s2=s1;
        for(int i:nums){
            if(i>m1){
                m3=m2; m2=m1; m1=i;
            }else if(i>m2){
                m3=m2; m2=i;
            }else if(i>m3) {
                m3=i;
            }
            
            if(i<s1){
                s2=s1; s1=i;
            }else if(i<s2){
                s2=i;
            }
        }
        return max((m1*m2*m3) , (m1*s1*s2));
    }
};