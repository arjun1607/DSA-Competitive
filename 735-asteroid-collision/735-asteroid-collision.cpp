class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> s;
        for(int i:nums){
            if(i>0) s.push(i);
            else{
                while(!s.empty() && s.top()>0 && s.top()<-i){
                    s.pop();
                }
                if(!s.empty() && s.top() == -i){
                    s.pop();
                    continue;
                }
                if(s.empty() || (!s.empty() && s.top()<0)){
                    s.push(i);
                }
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