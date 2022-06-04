class Solution {
public:
    // we want to maintain adj list such that, when we are at a node then all the nodes to which it is pointing are its children. it should not be parent or any node at the same level
    vector<vector<string>> ans;
    void dfs(unordered_map<string, unordered_set<string>> &adj, string src, string des, 
                  int lvl, vector<string> &path, unordered_map<string, bool> &vis){
        if(lvl==0) return;
        if(lvl==1){
            if(src==des) ans.push_back(path);
            return;
        }
        vis[src]=true;
        for(string i:adj[src]){
            if(!vis[i]){
                path.push_back(i);
                dfs(adj, i, des, lvl-1, path, vis);
                path.pop_back();
            }
        }
        vis[src]=false;
    }
    vector<vector<string>> findLadders(string begin, string end, vector<string>& wordlist) {
        set<string> dict;
        for(auto i:wordlist){
            dict.insert(i);
        }
        
        unordered_map<string, int> depth;      
        queue<string> q;
        q.push(begin);
        depth[begin]=1;
        
        unordered_map<string, unordered_set<string>> adj;
        while(!q.empty()){
            string word=q.front();
            q.pop();
            if(word==end) break;
            for(int i=0;i<word.size();i++){
                string temp=word;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(temp==word) continue;
                    if(dict.find(temp)!=dict.end()) {
                        if(depth.find(temp)==depth.end()){
                            q.push(temp);
                            depth[temp]=depth[word]+1;
                            cout<<temp<<" "<<depth[temp]<<endl;
                            adj[word].insert(temp);
                        }else if(depth[temp]==depth[word]+1){
                            adj[word].insert(temp);
                        }
                    } 
                }
            }
        }
    
        vector<string> path;
        path.push_back(begin);
        unordered_map<string, bool> vis;
        dfs(adj, begin, end, depth[end], path, vis);
        return ans;
    }
};