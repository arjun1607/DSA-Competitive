class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> Max(arr.size()), Min(arr.size());
        Max[0]=arr[0]; Min[arr.size()-1]=arr[arr.size()-1];
        for(int i=1;i<arr.size();i++) Max[i]=max(Max[i-1], arr[i]);
        for(int i=arr.size()-2;i>=0;i--) Min[i]=min(Min[i+1], arr[i]);
        int ans=0;
        for(int i=0;i<arr.size()-1;i++){
            if(Max[i]<=Min[i+1]) ans++;
        }
        return ans+1;
    }
};