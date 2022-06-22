class Node{
    public:
    Node* links[26];
    int sum;
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
class MapSum {
public:
    MapSum() {
        
    }
    Node *root = new Node();
    void insert(string s, int val) {
        Node *node = root;
        for(int i=0;i<s.size();i++){
            if(!node->containsKey(s[i])){
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->sum = val;
    }
    
    int dfs(Node *node){
        int ans = node->sum;
        for(int i=0;i<26;i++){
            if(node->links[i] != NULL){
                ans += dfs(node->links[i]);
            }
        }
        return ans;
    }
    int sum(string pre) {
        Node *node = root;
        for(int i=0;i<pre.size();i++){
            if(!node->containsKey(pre[i])){
                return 0;
            }
            node = node->get(pre[i]);
        }
        return dfs(node);
    }
};