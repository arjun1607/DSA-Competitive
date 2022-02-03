class Solution {
public:
     vector<string> mv(string s){
        vector<string> v;
        string t="";
        for(char c:s){
            if(c==' '){
                v.push_back(t);
                t="";
            }else t+=c;
        }
        v.push_back(t);
        return v;
    }
    string sortSentence(string str) {
        vector<string> s=mv(str);
        map<int,string> m;
        for(auto &i:s){
            int n=i[i.size()-1]-'0';
            i.pop_back();
            m[n]=i;
        }
        string ans="";
        for(auto i:m){
            ans+=i.second;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};