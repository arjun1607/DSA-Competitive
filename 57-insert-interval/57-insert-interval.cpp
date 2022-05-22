class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        // left part no intersection with newInterval
        // intervals whose end point is smaller than start point of newInterval
        // are not impacted, so directly add them
        while(i<arr.size() && arr[i][1] < newInterval[0]){
            ans.push_back(arr[i]);
            i++;
        }
        
        // interection part and merging them
        while(i<arr.size() && arr[i][0] <= newInterval[1]){
            newInterval[0]=min(arr[i][0], newInterval[0]);
            newInterval[1]=max(arr[i][1], newInterval[1]);
            i++;
        }
        // if there was no intersection only newInterval would be added
        ans.push_back(newInterval);
        
        // remaining right part (no intersection with newInterval) 
        while(i<arr.size()){
            ans.push_back(arr[i]);
            i++;
        }
        
        return ans;
    }
};