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
class Solution {
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
    
    string replaceWords(vector<string>& words, string s) {
        for(auto &word : words){
            insert(word);
        }
        
        string ans="";
        int i=0;
        while(i<s.size()){
            Node *node = root;
            string temp="";
            bool ok=true;
            while(s[i]!=' ' && i<s.size()){
                if(!node->containsKey(s[i])){
                    ok=false;
                    break;
                }
                temp+=s[i];
                node = node->get(s[i]);
                if(node->flag==true) break;
                i++;
            }
            while(s[i]!=' ' && i<s.size()){
                if(!ok) temp+=s[i];
                i++;
            }

            ans+=(temp + s[i++]);
        }
        ans.pop_back();
        return ans;
    }
};