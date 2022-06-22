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
    
};

class StreamChecker {
public:
    Node *root = new Node();
    void insert(string word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->flag=true;
    }
    
    StreamChecker(vector<string>& words) {
        for(auto word:words){
            reverse(word.begin(), word.end());
            insert(word);
        }
    }
    
    string s="";
    bool query(char ch) {
        s.push_back(ch);
        
        Node *node = root;
        for(int i=s.size()-1;i>=0;i--){
            if(!node->containsKey(s[i])){
                break;
            }
            node = node->get(s[i]);
            if(node->flag==true) return true;
        }
        return false;
    }
};