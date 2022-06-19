struct Node{
    Node* link[26];
    multiset<string> st;
};
class Solution {
public:
    Node* root = new Node();
    void insert_into_trie(string &str){
        Node* curr = root;
        for(auto &it : str){
            if(!curr->link[it - 'a']){
                curr->link[it - 'a'] = new Node();
            }
            curr = curr->link[it - 'a'];
            curr->st.insert(str);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(auto &it : products){
            insert_into_trie(it);
        }
        vector<vector<string>> ans;
        Node* curr = root;
        for(int i=0;i<searchWord.size();i++){
            char it = searchWord[i];
            vector<string> v;
            if(!curr->link[it - 'a']){
                while(i < searchWord.size()){
                    ans.push_back(v);
                    i++;
                }
                break;
            }
            curr = curr->link[it - 'a'];
            int cnt = 0;
            for(auto &itr : curr->st){
                cnt++;
                v.push_back(itr);
                if(cnt == 3) break;
            }
            ans.push_back(v);
        }
        return ans;
    }
};