class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
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
};