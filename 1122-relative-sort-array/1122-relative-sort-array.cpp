class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> m;                                                       
        for(int i:arr1) m[i]++;
        vector<int> ans;
        for(int i:arr2){
            int c=m[i];
            while(c--) ans.push_back(i);
            m.erase(i);
        }
        multiset<int> ms;
        for(auto i:m){
            int val=i.first;
            int c=i.second;
            while(c--) ms.insert(val);
        }
        for(int i:ms) ans.push_back(i);
        return ans;
    }
};