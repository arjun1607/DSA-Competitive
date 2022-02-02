class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int> lmax(n), rmax(n);
        lmax[0]=h[0]; rmax[n-1]=h[n-1];
        for(int i=1;i<n;i++) lmax[i]=(h[i]>lmax[i-1])?h[i]:lmax[i-1];
        for(int i=n-2;i>=0;i--) rmax[i]=(h[i]>rmax[i+1])?h[i]:rmax[i+1];
        int totalwater=0;
        for(int i=1;i<=n-2;i++){
            int waterstored = min(lmax[i-1], rmax[i+1])-h[i];
            if(waterstored>0) totalwater+=waterstored;
        }
        return totalwater;
    }
};