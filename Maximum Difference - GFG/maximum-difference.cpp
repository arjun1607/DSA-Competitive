// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int arr[], int n){
        stack<int> s;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            // only keep unique elements in stack
            // otherwise just below element can be duplicate one
            if(!s.empty() && arr[s.top()]==arr[i]) continue;
            
            while(!s.empty() && arr[i]<arr[s.top()]){
                int nsr=arr[i];
                s.pop();
                int nsl=(s.empty()==true)?0:arr[s.top()];
                ans=max(ans, abs(nsr-nsl));
            }
            s.push(i);
        }
        
        // if all the elements are increasing
        while(!s.empty()){
            int nsr=0;
            s.pop();
            int nsl=(s.empty()==true)?0:arr[s.top()];
            ans=max(ans, abs(nsr-nsl));
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends