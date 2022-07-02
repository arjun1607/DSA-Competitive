class Solution {
public:
    int maxArea(int h, int w, vector<int>& Hcuts, vector<int>& Vcuts) {
  Hcuts.push_back(0); Hcuts.push_back(h); 
        Vcuts.push_back(0); Vcuts.push_back(w); 
        sort(Hcuts.begin(),Hcuts.end());
        sort(Vcuts.begin(),Vcuts.end());
        int maxlen=0, maxwidth=0;
        for(int i=1;i<Hcuts.size();i++)
            maxlen= max(maxlen, Hcuts[i]-Hcuts[i-1]);
        for(int i=1;i<Vcuts.size();i++)
            maxwidth= max(maxwidth, Vcuts[i]-Vcuts[i-1]);
        return (1LL*maxlen*maxwidth)%1000000007;
    }
};