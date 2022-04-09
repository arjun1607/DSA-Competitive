class Solution {
public:
     int lps(string s) {
        int n=s.size();
        vector<int> front(n, 0), curr(n, 0);
        for(int i=n-1;i>=0;i--){
            curr[i]=1;
            for(int j=i+1;j<n;j++){
                  if(s[i]==s[j])  curr[j]=2+front[j-1]; 
                  else curr[j] = max(front[j], curr[j-1]);
            }
            front=curr;
        }
        return front[n-1];
    
    }
    int minInsertions(string s) {
        return s.size()-lps(s);
    }
};