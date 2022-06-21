class WordFilter {
public:
    unordered_map<string, int>  map;
    WordFilter(vector<string>& words) {
        for(int k=0;k<words.size();k++){
            string s=words[k], pre="";
            for(int i=0;i<s.size();i++){
                pre+=s[i];
                string suf="";
                for(int j=s.size()-1; j>=0; j--){
                    suf = s[j] + suf;
                    map[pre+'#'+suf] = k;
                }
            }
        }
    }
    
    int f(string pre, string suf) {
        if(map.find(pre+'#'+suf) == map.end()) return -1;
        return map[pre+'#'+suf];
    }
};

// brute force => take every string, for all prefixes take all possible suffixes and store in hashmap with index