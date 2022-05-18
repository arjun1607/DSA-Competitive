class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size(), m=num2.size();
        vector<int> arr(n+m, 0);
        for(int j=m-1;j>=0;j--){
            for(int i=n-1;i>=0;i--){
                int val =  (num2[j]-'0')*(num1[i]-'0') + arr[i+j+1];
                int carry = val/10;
                int tobeplaced = val%10;
                arr[i+j+1] = tobeplaced;
                arr[i+j] += carry;
            }
        }
        string ans="";
        for(int i:arr){
            if(i==0 && ans.size()==0) continue;
            ans+='0'+i;
        }
        return ans.size()==0?"0":ans;
    }
};