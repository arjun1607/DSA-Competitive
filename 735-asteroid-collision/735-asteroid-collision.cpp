class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> s;
        int i=0;
        while(i<arr.size()){
            if(s.empty() || arr[i]>0 || s.top()<0){
                s.push(arr[i]);
                i++;
            }
            else if(-arr[i]<s.top()) i++;
            else if(-arr[i]>=s.top()){
                if(-arr[i]==s.top()) i++;
                s.pop();
            }            
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};