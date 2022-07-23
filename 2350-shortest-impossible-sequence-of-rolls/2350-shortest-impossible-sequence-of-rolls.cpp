class Solution {
public:
  
    
    bool all(int size, int k, vector<int> &arr){
        vector<int> v(k, 0);
        int ans=0, c=0;
        for(int i=0;i<arr.size();i++){
            if(v[arr[i]-1]==ans){ 
                c++;
                v[arr[i]-1]++;                     
            }
            if(c==k){
                c=0;
                ans++;
            }
        }
        return ans>=size;
    }
    
    int shortestSequence(vector<int>& arr, int k) {
        vector<int> v(k, 0);
        int ans=0, c=0;
        for(int i=0;i<arr.size();i++){
            if(v[arr[i]-1]==ans){ 
                c++;
                v[arr[i]-1]++;                     
            }
            if(c==k){
                c=0;
                ans++;
            }
        }
        return ans+1;
    }
    
};