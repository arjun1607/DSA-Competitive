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
            if(lvl==4) cout<<word<<endl;
           for(int i=0;i<word.size();i++){
                string temp=word;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(temp==word) continue;
                    if(s.find(temp)!=s.end()){
                        s.erase(temp);
                        q.push({temp, lvl+1});
                    }                    
                }
            }
        }
        return 0;
    }
};