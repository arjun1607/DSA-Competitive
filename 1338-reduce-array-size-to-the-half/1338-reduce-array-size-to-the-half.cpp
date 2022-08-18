class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i:arr) m[i]++;
        multiset<int, greater<int>> s;
        for(auto i:m){
            s.insert(i.second);
        }
        int n=arr.size();
        int t=0, ans=0;
        for(auto i:s){
            t+=i;
            ans++;
            if(t>=n/2){
                break;
            }
        }
        return ans;
    }
};