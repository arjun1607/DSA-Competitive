class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        int i=0, j=v.size()-1;
        while(i<=j){
            if(v[j]%2==1) j--;
            else if(v[i]%2==1) swap(v[i], v[j]);
            else i++;
        }
        return v;
    }
};