class Solution {
public:
    int lis(vector<int> &v){
        vector<int> dp;
        for(int &i:v){
            auto it=upper_bound(dp.begin(), dp.end(), i);
            if(it==dp.end()) dp.push_back(i);
            else *it=i;
        }
        return dp.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size(), ans=0;
        for(int i=0;i<k;i++){
            vector<int> v;
            for(int j=i; j<n; j+=k){
                v.push_back(arr[j]);
            }
            ans += v.size() - lis(v);
        }
        return ans;
    }
};