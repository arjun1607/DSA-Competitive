class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0, t=0;
        for(int i=0;i<logs.size();i++){
            string s=logs[i];
            int count=0;
            for(auto c:s) if(c=='.') count++;
            if(count==0) { ans++; t++; }
            else if(count==2 && t!=0) { ans--; t--; }
        }
        return (ans<0)?0:ans;
    }
};