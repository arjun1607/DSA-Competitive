class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        vector<int> ans(n, -1);
        for(int i=0;i<2*n;i++){
            while(!s.empty() && arr[i%n]>arr[s.top()]){
                ans[s.top()] = arr[i%n];
                s.pop();
            }
            if(i<n) s.push(i);
        }
        return ans;
    }
};