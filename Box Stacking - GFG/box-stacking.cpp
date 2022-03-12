// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    static bool cmp(vector<int> a, vector<int> b){
        if(a[1]==b[1]) return a[2]>b[2];
        else return a[1]<b[1];
    }
    int maxHeight(int h[],int w[],int l[],int n){
        vector<vector<int>> v(3*n);
        for(int i=0;i<n;i++){
            v[3*i]={h[i], min(w[i], l[i]), max(w[i], l[i])};
            v[3*i+1]={w[i], min(h[i], l[i]), max(h[i], l[i])};
            v[3*i+2]={l[i], min(h[i], w[i]), max(h[i], w[i])};
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> dp(3*n);
        dp[0]=v[0][0];
        for(int i=1;i<3*n;i++){
            int ans=v[i][0];
            for(int j=0;j<i;j++){
                if(v[j][2] < v[i][2]) ans=max(ans, dp[j]+v[i][0]);
            }
            dp[i]=ans;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends