class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int x=accumulate(a.begin(), a.end(), 0);
        int y=accumulate(b.begin(), b.end(), 0);
        int n=(y-x)/2;
        set<int> s; for(int i:b) s.insert(i);
        vector<int> ans(2);
        for(int i:a){
            if(s.find(i+n)!=s.end()){
                ans[0]=i;
                ans[1]=i+n;
                break;
            }
        }
        return ans;
    }
};