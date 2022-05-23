class Solution {
public:
    int area(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        int area=INT_MIN;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || arr[i]<arr[s.top()])){
                int nsr=i;
                int x=s.top();
                s.pop();
                int nsl=s.empty()?-1:s.top();
                area=max(area,arr[x]*(nsr-nsl-1));
            }
            if(i<n) s.push(i);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), ans=INT_MIN;
        vector<int> temp(m, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') temp[j]=0;
                else temp[j]++;
            }
            ans=max(ans, area(temp));
        }
        return ans;
    }
};