class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> s;
        for(int i=0;i<nums.size();i++){
            while(!s.empty() && k>0 && s.top() > nums[i]){
                s.pop();
                k--;
            }
            if(s.empty() && nums[i]=='0') continue;
            s.push(nums[i]);
        }
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.size()==0 ?  "0" : ans;
    }
};