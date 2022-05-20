class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=ceil(b.size()*1.0/a.size());
        string text=a;
        for(int i=1;i<n;i++) text+=a;
        if(text.find(b)!=string::npos) return n;
        else {
            text+=a;
            if(text.find(b)!=string::npos) return n+1;
        }
        return -1;
    }
};












