class Node
{
    public:
    Node *links[27]={NULL};
    int maxidx=-1;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }  
};

class WordFilter {
public:
    Node *root = new Node();
    void insert(string s, int k){
        Node *node = root;
        for(int i=0;i<s.size();i++){
            if(!node->containsKey(s[i])){
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->maxidx = k;
    }
    int search(string s){
        Node *node = root;
        for(int i=0;i<s.size();i++){
            if(!node->containsKey(s[i])){
                return -1;
            }
            node = node->get(s[i]);
        }
        return node->maxidx;
    }
    WordFilter(vector<string>& words) {
        for(int k=0;k<words.size();k++){
            string s=words[k], pre="";
            for(int i=0;i<s.size();i++){
                pre+=s[i];
                string suf="";
                for(int j=s.size()-1; j>=0; j--){
                    suf = s[j] + suf;
                    insert(pre+'{'+suf, k);
                }
            }
        }
    }
    
    int f(string pre, string suf) {
        return search(pre+'{'+suf);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */