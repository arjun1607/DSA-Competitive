class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s;
        int maxi = INT_MIN, n=arr.size();
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || arr[i] < arr[s.top()])){
                int nsr = i;
                int idx = s.top(); 
                s.pop();
                int nsl = !s.empty() ? s.top() : -1;
                maxi = max(maxi, arr[idx] * (nsr - nsl - 1));
            }
            if(i<n) s.push(i);
        }
        return maxi;
    }
};