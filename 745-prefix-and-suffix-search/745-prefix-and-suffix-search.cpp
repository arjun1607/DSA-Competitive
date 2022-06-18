#define ll long long
#define vb vector<bool>
#define vi vector<int>
#define vl vector<long long>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define all(i) i.begin(),i.end()
#define loopf(i,s,e) for(int i = s; i < e; i++)
#define loopb(i,s,e) for(int i = s; i >= e; i--)
inline int getMid(int i,int j) { return i+(j-i)/2; }

struct TrieNode {
    unordered_map<char,TrieNode*> children;
    int idx = -1;
};

struct Trie {
    TrieNode* root;

    Trie(vector<string>& words) {
        this->root = new TrieNode();
        loopf(i,0,words.size()) {
            string word = "#"+words[i];
            loopb(j,words[i].length()-1,0) {
                word = words[i][j]+word;
                insert(word,i);
            }
        }
    }

    void insert(string& s, int index) {
        auto p = root;
        loopf(i,0,s.length()) {
            if(p->children.count(s[i]) == 0) p->children[s[i]] = new TrieNode();
            p = p->children[s[i]];
        }
        p->idx = index;
    }

    int query(string& pref, string& suff) {
        string s = suff+"#"+pref;
        auto p = root;
        loopf(i,0,s.length()) {
            if(p->children.count(s[i]) == 0) return -1;
            p = p->children[s[i]];
        }

        return dfs(p);
    }

    int dfs(TrieNode* root) {
        int res = root->idx;
        for(auto i:root->children) {
            res = max(res,dfs(i.second));
        }
        return res;
    }
};

class WordFilter {
public:
    Trie *t;

    WordFilter(vector<string>& words) {
        this->t = new Trie(words);
    }
    
    int f(string prefix, string suffix) {
        return t->query(prefix,suffix);
    }
};