class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& arr, int s, int f) {
        int n=arr.size();
        vector<int> prefixsum(n);
        for(int i=0;i<n;i++){
            if(i==0) prefixsum[i]=arr[i];
            else prefixsum[i]=prefixsum[i-1]+arr[i];
        }
        int ans=prefixsum[f+s-1];
        int fmax=prefixsum[f-1];
        for(int i=f+s; i<n; i++){
            int last_Ssum = prefixsum[i]-prefixsum[i-s];
            fmax=max(fmax, prefixsum[i-s]-prefixsum[i-s-f]);
            ans=max(ans, fmax+last_Ssum);
        }
        int smax=prefixsum[s-1];
        for(int i=f+s; i<n; i++){
            int last_Fsum = prefixsum[i]-prefixsum[i-f];
            smax=max(smax, prefixsum[i-f]-prefixsum[i-f-s]);
            ans=max(ans, smax+last_Fsum);
        }
        return ans;
    }
};