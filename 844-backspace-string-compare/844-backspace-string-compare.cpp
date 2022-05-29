class Solution {
    string remove(string s){
        string ans="";
        for(char c:s){
            if(c=='#'){
                if(!ans.empty())
                    ans.pop_back();
            }
            else ans+=c;
        }
        return ans;
    }
public:
    bool backspaceCompare(string s, string t) {
        return remove(s)==remove(t);
        
        /*
       int i=s.size()-1, j=t.size()-1;
        while(i>0 && j>0){
            if(s[i]==t[j]){
                i--; j--;
            }
            else if(s[i]=='#' && t[j]!='#'){
                while()
            }
            else if(s[i]!='#' && t[j]=='#') j-=2;
            else {
                i-=2; j-=2;
            }
        }
        return i==-1 && j==-1;
        */
    }
};