class Solution {
public:
    bool isCovered(vector<vector<int>>& arr, int l, int r) {
        vector<int> range(52, 0);
        for(auto i:arr){
            range[i[0]]+=1;
            range[i[1]+1]+=-1;
        }
        for(int i=1;i<=50;i++) range[i]+=range[i-1];
        for(int i=l;i<=r;i++) if(range[i]<=0) return false;
        return true;
    }
};