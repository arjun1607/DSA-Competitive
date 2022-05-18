class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        int start=0, end=INT_MAX, Max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0], i, 0});
            Max=max(Max, nums[i][0]);
        }
        
        while(1){
            auto it=pq.top();
            int val=it[0], row=it[1], col=it[2];
            pq.pop();
            if(Max-val < end-start){
                start=val; 
                end=Max;
            }
            if(col+1 == nums[row].size()) break;
            pq.push({nums[row][col+1], row, col+1});
            Max=max(Max, nums[row][col+1]);
        }
        
        return {start, end};
    }
};