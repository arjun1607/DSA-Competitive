class Solution {
public:
    int maxRepeating(string s, string t) {
        int max=s.size()/t.size();
        int k=0;
        string ptr=t;
        for(int i=1;i<=max;i++){
            if(s.find(ptr)!=string::npos) k++;
            ptr+=t;
        }
        return k;
    }
};