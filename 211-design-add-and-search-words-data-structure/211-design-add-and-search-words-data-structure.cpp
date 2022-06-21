class Node{
    public: 
    Node* links[26];
    bool flag;
    
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};
class WordDictionary {
private : Node *root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    

    bool dfs(int i, string s, Node *node){
        if(i==s.size()){
            return node->flag;
        }
        if(s[i]!='.'){
            if(!node->containsKey(s[i])){
                return false;
            }
            return dfs(i+1, s, node->get(s[i]));
        }
        else{
            bool temp=false;
            for(int k=0;k<26;k++){
                if(node->links[k] != NULL){
                    temp = (temp || dfs(i+1, s, node->links[k]));
                } 
            }
            return temp;
        }
    }
    bool search(string word) {
        Node *node=root;
        return dfs(0, word, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */