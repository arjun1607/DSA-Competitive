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
        // return remove(s)==remove(t);

        int i=s.size()-1, j=t.size()-1;
        int  bspcount_s=0, bspcount_t=0;
        while(i>=0 || j>=0){
            // deleting the char
            while(i>=0 && (s[i]=='#' || bspcount_s>0)){
                if(s[i]=='#') bspcount_s++;
                else bspcount_s--;
                i--;
            }
            while(j>=0 && (t[j]=='#' || bspcount_t>0)){
                if(t[j]=='#') bspcount_t++;
                else bspcount_t--;
                j--;
            }
            
            if(i>=0 && j>=0 && s[i]==t[j]){
                i--; j--;
            }else{
                return i==-1 && j==-1;
            }
        }
        return true;
    }
};