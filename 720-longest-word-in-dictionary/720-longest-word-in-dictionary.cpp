class Node{
    public:
    Node* links[26];
    int flag;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
};

class Solution {
public:
    Node *root = new Node();
    void insert(string s) {
        Node *node = root;
        for(int i=0;i<s.size();i++){
            if(!node->containsKey(s[i])){
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->flag = true;
    }
    
    void dfs(Node *node, string temp, string &ans){
        ans = (temp.size() > ans.size()) ? temp : ans;
        for(int i=0;i<26;i++){
            if(node->links[i]!=NULL && node->links[i]->flag!=false){
                temp += ('a'+i);
                dfs(node->links[i], temp, ans);
                temp.pop_back();
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        for(auto &s:words){
            insert(s);
        }
        
        
        Node *node = root;
        string ans;
        dfs(node, "", ans);
        return ans;
        /*
        // For every word in the input list, we can check whether all prefixes of that word are in the trie or not
        sort(words.begin(), words.end());
        string ans="";
        for(auto &s:words){
            Node *node = root;
            int i=0;
            while(i<s.size()){
                if(node->containsKey(s[i])){
                    node = node->get(s[i]);
                    if(!node->flag) break;
                }
                else break;
                i++;
            }
            if(i==s.size() && s.size()>ans.size()){
                ans = s;
            }
        }
        
        return ans;
        */
    }
};