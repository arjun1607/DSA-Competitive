class Node{
    public:
    Node *links[26]={NULL};
    bool flag;
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
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->flag=true;
    }
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->flag;
    }
    
    bool isConcat(string s){
        Node *node = root;
        for(int i=0;i<s.size();i++){
            if(!node->containsKey(s[i])){
                return false;
            }
            node = node->get(s[i]);
            if(node->flag==true){
                string suffix = s.substr(i+1);
                if(search(suffix) || isConcat(suffix)){
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &s:words){
            insert(s);
        }
        vector<string> ans;
        for(auto &s:words){
            if(isConcat(s)){
                ans.push_back(s);
            }
        }
        return ans;
    }
};