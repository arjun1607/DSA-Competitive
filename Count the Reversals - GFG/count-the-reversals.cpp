// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends
int countRev (string str){
    stack<char> s;
    for(char &c:str){
        if(c=='{') s.push(c);
        else{
            if(!s.empty() && s.top()=='{') s.pop();
            else s.push(c);
        }
    }
    int opening=0, closing=0;
    while(!s.empty()){
        if(s.top()=='{') opening++;
        else closing++;
        s.pop();
    }
    if(opening%2==0 && closing%2==0) return (opening/2+closing/2);
    else if(opening&1 && closing&1) return (2+(opening-1)/2+(closing-1)/2);
    else return -1;
}
