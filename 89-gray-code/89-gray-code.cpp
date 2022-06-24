class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1) return {0,1};      
        vector<int> t= grayCode(n-1);
        vector<int> v(t);
        for(int i=t.size()-1;i>=0;i--) v.push_back(t[i] | (1<<(n-1)));
        return v;
    }
};