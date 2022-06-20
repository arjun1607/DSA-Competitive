class Node{
    public:
    Node *links[26];
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class Solution {
public:
    int ans=0;
    void dfs(Node *node, int len){
        bool leaf=true;
        for(int i=0;i<26;i++){
            if(node->links[i]!=NULL){
                leaf=false;
                dfs(node->links[i], len+1);
            }
        }
        if(leaf){
            ans+=(len+1);
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        Node *root = new Node();
        // inserting in trienode
        for(auto &s:words){
            Node *node=root;
            for(int i=s.size()-1; i>=0;i--){
                if(!node->containsKey(s[i])){
                    node->put(s[i], new Node());
                }
                node = node->get(s[i]);
            }
        }
        
        dfs(root, 0);
        return ans;
    }
};