class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1) return {0,1};      
        vector<int> recans = grayCode(n-1);
        vector<int> myans(recans.begin(), recans.end());
        for(int i=recans.size()-1;i>=0;i--){
            myans.push_back(recans[i] | (1<<(n-1)));
        }
        return myans;
    }
};