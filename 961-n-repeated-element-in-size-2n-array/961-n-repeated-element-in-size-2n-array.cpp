class Solution {
public:
    int repeatedNTimes(vector<int>& arr) {
        int ans;
        for(int i=0;i<arr.size()-3;i++){
            if(arr[i]==arr[i+1] || arr[i]==arr[i+2] || arr[i]==arr[i+3]){ 
                ans=arr[i]; break;
            }else if(arr[i+1]==arr[i+2] || arr[i+1]==arr[i+3]){
                ans=arr[i+1]; break;
            }else if(arr[i+2]==arr[i+3]){
                ans=arr[i+2]; break;
            }
        }
        return ans;
    }
};