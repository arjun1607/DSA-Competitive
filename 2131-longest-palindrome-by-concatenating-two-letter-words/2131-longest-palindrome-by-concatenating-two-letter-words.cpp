class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        multiset<string> s; 
        int ans=0;
        for(auto i:words){
            string t=i; reverse(t.begin(), t.end());
            if(s.find(t)!=s.end()){
                ans+=4;
                s.erase(s.find(t));
            }else s.insert(i);
        }
        for(auto i:s){
            if(i[0]==i[1]){
                ans+=2; break;
            }
        }
        return ans;
    }
};