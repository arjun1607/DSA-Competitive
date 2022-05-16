class Solution {
public:
    int maximumSwap(int n) {
        string s=to_string(n);
        vector<int> lastpos(10, -1);
        for(int i=s.size()-1;i>=0;i--){
            int val=s[i]-'0';
            if(lastpos[val]==-1) lastpos[val]=i;
        }
        for(int i=0;i<s.size();i++){
            bool flag=false;
            for(int j=9;j>s[i]-'0';j--){
                if(lastpos[j]>i){
                    swap(s[i], s[lastpos[j]]);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        return stoi(s);
    }
};