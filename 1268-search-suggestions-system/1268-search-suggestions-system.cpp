class Node{
    public:
    Node* links[26];
    vector<string> v;
    bool containsKey(char ch){
        return  links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void push(string s){
        if(v.size() < 3){
            v.push_back(s);
        }
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Node *root = new Node();
        for(auto &s:products){
            Node *node = root;
            for(int i=0;i<s.size();i++){
                if(!node->containsKey(s[i])){
                    node->put(s[i], new Node());
                }
                node = node->get(s[i]);
                node->push(s);
            }
        }
        
        vector<vector<string>> ans;
        Node *node = root;
        int i=0;
        while(i<searchWord.size()){
            if(!node->containsKey(searchWord[i])){
                break;
            }
            node = node->get(searchWord[i]);
            ans.push_back(node->v);
            i++;
        }
        while(i<searchWord.size()){
            ans.push_back({});
            i++;
        }
        
        return ans;
    }
};