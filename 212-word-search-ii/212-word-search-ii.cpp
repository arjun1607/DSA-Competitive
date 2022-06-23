class Node{
    public:
    Node *links[26]={NULL};
    string end="";
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
};
class Solution {
public:
    Node *root = new Node();
    void insert(string s){
        Node *node = root;
        for(int i=0;i<s.size();i++){
            if(!node->containsKey(s[i])){
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->end = s;
    }
    
    vector<string> ans;
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &vis, Node *node){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || 
                         vis[i][j]==true || !node->containsKey(grid[i][j])){
            return;
        }
 
        vis[i][j]=true;
        Node *next = node->get(grid[i][j]);
        
        if(next->end!=""){
            ans.push_back(next->end);
            next->end = "";
        }
        
        dfs(grid, i-1, j, vis, next);
        dfs(grid, i, j-1, vis, next);
        dfs(grid, i+1, j, vis, next);
        dfs(grid, i, j+1, vis, next);
        vis[i][j]=false;
    }

    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        for(auto &s:words){
            insert(s);
        }
    
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Node *node = root;
                if(node->containsKey(grid[i][j])){
                    dfs(grid, i, j, vis, node);
                }
            }
        }
        return ans;
    }
};