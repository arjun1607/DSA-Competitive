class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int a0=a[0], b0=b[0];
        int aa0=0, ab0=0, ba0=0, bb0=0;
        for(int i=0;i<a.size();i++){
            if(aa0!=INT_MAX && a[i]!=a0){
                if(b[i]==a0) aa0++;
                else aa0=INT_MAX;
            }
            if(ab0!=INT_MAX && a[i]!=b0){
                if(b[i]==b0) ab0++;
                else ab0=INT_MAX;
            }
            if(ba0!=INT_MAX && b[i]!=a0){
                if(a[i]==a0) ba0++;
                else ba0=INT_MAX;
            }
            if(bb0!=INT_MAX && b[i]!=b0){
                if(a[i]==b0) bb0++;
                else bb0=INT_MAX;
            }
        }
        cout<<aa0<<" "<<ab0<<" "<<ba0<<" "<<bb0;
        int ans=min({aa0, ab0, ba0, bb0});
        return ans==INT_MAX?-1:ans;
    }
};