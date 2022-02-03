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
    bool areNumbersAscending(string str) {
        vector<string> s=mv(str);
        int n=0;
        for(auto i:s){
            if(i[0]-'0'>=0 && i[0]-'0'<=9){
                if(stoi(i)<=n) return false;
                else n=stoi(i);
            }
        }
        return true;
    }
};