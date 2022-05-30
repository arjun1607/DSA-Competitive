class Solution {
public:
    string removeDuplicateLetters(string str) {
        unordered_map<char, int> fmap;
        unordered_map<char, bool> vis;
        for(char c:str){
            fmap[c]++;
            vis[c]=false;
        }
        stack<char> s;
        for(char c:str){
            cout<<c<<" "<<vis[c]<<endl;
            if(!vis[c]){
                while(!s.empty() && s.top()>c && fmap[s.top()]>0){
                    cout<<c<<" "<<s.top()<<endl;
                    vis[s.top()]=false;
                    s.pop();
                }
                s.push(c);
                vis[c]=true;
            }
            fmap[c]--;
        }
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};