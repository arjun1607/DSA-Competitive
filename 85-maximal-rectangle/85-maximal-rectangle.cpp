class Solution {
public:
    int area(vector<int> &arr){
        stack<int> s;
        int maxi = 0, n=arr.size();
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || arr[i] < arr[s.top()])){
                int nsr = i;
                int idx = s.top();
                s.pop();
                int nsl = !s.empty() ? s.top() : -1;
                maxi = max(maxi, arr[idx] * (nsr - nsl -1));
            }
            if(i<n) s.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& grid) {
        int maxi = 0;
        vector<int> temp(grid[0].size(), 0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp[j] = (grid[i][j] == '1') ? ++temp[j] : 0;
            }
            maxi = max(maxi, area(temp));
        }
        return maxi;
    }
};