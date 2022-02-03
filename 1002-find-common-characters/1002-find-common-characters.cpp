class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        multiset<char> a, b;
        for(char c:words[0]) a.insert(c);
        for(int i=1;i<words.size();i++){
            for(char c:words[i]){
                auto it=a.find(c);
                if(it!=a.end()){
                    a.erase(it);
                    b.insert(c);
                }
            }
            a.clear();
            for(char c:b) a.insert(c);
            if(i!=words.size()-1) b.clear();
        }
        vector<string> ans;
        for(char c:b){
            string s(1,c);
            ans.push_back(s); 
        }
        return ans;
    }
};