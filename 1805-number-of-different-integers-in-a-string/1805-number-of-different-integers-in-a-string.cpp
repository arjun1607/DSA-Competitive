class Solution {
public:
    vector<string> mv(string s){
        vector<string> v;
        string t="";
        bool flag=false;
        for(char c:s){
            if(c==' '){
                if(flag==true){
                v.push_back(t);
                flag=false;
                }
                t="";
            }else { t+=c; flag=true; }
        }
        if(t!="") v.push_back(t);
        return v;
    }
    int numDifferentIntegers(string s) {
        for(char &c:s) if(c>='a' && c<='z') c=' ';
        vector<string> v=mv(s);
        for(auto &i:v){
            if(i[0]=='0'){
                reverse(i.begin(), i.end());
                while(i.back()=='0') i.pop_back();
                reverse(i.begin(), i.end());
            }
        }
        set<string> set; for(auto i:v) set.insert(i);
        return set.size();
    }
};