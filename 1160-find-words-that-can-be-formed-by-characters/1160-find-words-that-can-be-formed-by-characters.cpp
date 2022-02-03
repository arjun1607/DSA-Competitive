class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> m; for(char c:chars) m[c]++;
        int ans=0;
        for(string s:words){
            string used="";
            bool flag=true;
            for(char c:s){
                if(m.find(c)!=m.end()){
                    m[c]--;
                    used+=c;
                    if(m[c]<0){
                        flag=false;
                        break;
                    }
                }
                else {
                    flag=false;
                    break;
                }
            }
            if(flag==true) ans+=s.size();
            for(char c:used) m[c]++;
        }
        return ans;
    }
};