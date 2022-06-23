class Solution {
public:
    set<string> st;
    bool isConcat(string s){
        string pre="";
        for(int i=1;i<s.size();i++){
            string suffix=s.substr(i);
            if(st.find(s.substr(0,i))!=st.end() && (st.find(suffix)!=st.end() || isConcat(suffix))){
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &s:words){
            st.insert(s);
        }
        vector<string> ans;
        for(auto &s:words){
            if(isConcat(s)){
                ans.push_back(s);
            }
        }
        return ans;
    }
};