class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordlist) {
        // next possible node ko apne word ko change krte hue dekhna in set
        set<string> s;
        for(auto i:wordlist){
            s.insert(i);
        }
        queue<pair<string, int>> q;
        q.push({begin, 1});
        while(!q.empty()){
            auto pair=q.front();
            q.pop();
            string word=pair.first;
            int lvl=pair.second;
            if(word==end) return lvl;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    if(ch!=original){
                        word[i]=ch;
                        if(s.find(word)!=s.end()){
                            s.erase(word);
                            q.push({word, lvl+1});
                        }
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};