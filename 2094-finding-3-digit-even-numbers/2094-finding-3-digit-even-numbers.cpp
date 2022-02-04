class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {
        unordered_map<int,int> m; for(int i:d) m[i]++;
        vector<int> ans;
        for(int i=100;i<=999;i++){
            vector<int> used;
            bool flag=true;
            int n=i;
            while(n!=0){
                if(m[n%10]>0){
                    used.push_back(n%10);
                    m[n%10]--;
                }else{
                    flag=false;
                    break;
                }
                n=n/10;
            }
            if(flag && i%2==0) ans.push_back(i);
            for(int j:used) m[j]++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};