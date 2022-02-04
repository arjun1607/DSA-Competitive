class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {
        // Check for all numbers between 100 to 999 whether it can be formed by the digits present in digits vector
        unordered_map<int,int> m; for(int i:d) m[i]++;
        vector<int> ans;
        for(int i=100;i<=999;i+=2){
            vector<int> used;
            int n=i;
            while(n!=0){
                if(m[n%10]>0){
                    used.push_back(n%10);
                    m[n%10]--;
                }else break;
                n=n/10;
            }
            if(used.size()==3) ans.push_back(i);
            for(int j:used) m[j]++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};