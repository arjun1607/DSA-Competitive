class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> s;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                while(!s.empty() && s.top()>0 && -arr[i]>s.top()){
                    s.pop();
                }
                if(!s.empty() && s.top()==-arr[i]){
                    s.pop();
                    continue;
                }
                if(s.empty() || (!s.empty() && s.top()<0)) s.push(arr[i]);
            }
            else s.push(arr[i]);
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