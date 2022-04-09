class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m; 
        for(int &i:nums) m[i]++;
        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        for(auto &it:m){
            pq.push({it.second, it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            auto it=pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
    }
};