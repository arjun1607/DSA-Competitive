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
    
    string longestWord(vector<string>& words) {
        for(auto &s:words){
            insert(s);
        }
        
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
    }
};