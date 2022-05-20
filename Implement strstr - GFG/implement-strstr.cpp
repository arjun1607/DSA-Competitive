// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x){
    s=x+'#'+s;
    vector<int> z(s.size(), 0);
    int l=0, r=0;
    for(int i=1;i<s.size();i++){
        if(i<=r){
            z[i]=min(z[0+i-l], r-i+1);
        }
        while(i+z[i]<s.size() && s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if(i+z[i]-1 > r){
            l=i;
            r=i+z[i]-1;
        }
    }
    int ans=-1;
    for(int i=0;i<z.size();i++){
        if(z[i]==x.size()) {
            ans=i-x.size()-1;
            break;
        }
    }
    return ans;
}