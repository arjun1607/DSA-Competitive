class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        k=arr.size()-k;
        int i=0, j=0;
        int sum=0, ans=INT_MAX;
        while(j<arr.size()){
            sum+=arr[j];
            if(j-i+1==k){
                ans = min(ans, sum);
                cout<<ans<<endl;
            }else if(j-i+1>k){
                sum-=arr[i];
                i++;
                ans = min(ans, sum);
            }
            j++;
        }
        int totsum=0;
        for(int i:arr) totsum+=i;
        return totsum - ans;
    }
};