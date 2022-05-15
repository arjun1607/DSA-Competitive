class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        if(s.size()==1) return -1;
        
        int i,j;
        for(i=s.size()-2; i>=0; i--) if(s[i]-'0' < s[i+1]-'0') break;
        if(i==-1) return -1;
        
        for(j=s.size()-1; j>i; j--) if(s[j]-'0' > s[i]-'0') break;
        swap(s[i], s[j]);
        
        reverse(s.begin()+i+1, s.end());
        
        long ans=stol(s);
        return ans>INT_MAX?-1:ans;
    }
};