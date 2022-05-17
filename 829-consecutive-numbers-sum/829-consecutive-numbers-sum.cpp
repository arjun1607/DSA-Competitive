class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int k=1, ans=0;
        while(n-((k-1)*k)/2 > 0){
            if((n-((k-1)*k)/2) % k == 0) ans++;
            k++;
        }
        return ans;
    }
};