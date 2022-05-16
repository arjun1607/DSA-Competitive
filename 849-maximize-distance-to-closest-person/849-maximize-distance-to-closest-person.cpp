class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int n=s.size();
        int left=0, mid=0, right=0, i=0;
        if(s[0]==0){
            while(i<n && s[i]==0) i++;
            left=i;
        }
        int j=i+1;
        while(true){
            while(j<n && s[j]==0) j++;
            if(j==n) break;
            mid=max(mid, (i+j)/2-i);
            i=j;
            j++;
        }
        if(s[n-1]==0){
            i=n-1;
            while(i>=0 && s[i]==0) i--;
            right=n-1-i;
        }
        return max({left, mid, right});
    }
};