// class Node{
//     public:
//     Node *links[26];
//     bool flag;
//     bool containsKey(char ch){
//         return links[ch-'a']!=NULL;
//     }
//     void put(char ch, Node* node){
//         links[ch-'a'] = node;
//     }
//     Node* get(char ch){
//         return links[ch-'a'];
//     }
// };
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        /*
        Node *root = new Node();
        int ans=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            reverse(s.begin(), s.end());
            Node *node = root;
            int temp=0;
            bool longer=false;
            for(int j=0;j<s.size();j++){
                if(!node->containsKey(s[j])){
                    node->put(s[j], new Node());
                    if(j==s.size()-1){
                        longer=true;
                    }
                }
                temp++;
                if(node->flag==true) temp=0;
                node=node->get(s[j]);
            }
            node->flag=true;
            if(longer){
                ans+=(temp+1);
            }
        }
        return ans;
        */
        set<string> s1(words.begin(), words.end());
        set<string> s2(words.begin(), words.end());   
        for(auto &s:s1){
            for(int i=1;i<s.size();i++){
                if(s2.find(s.substr(i)) != s2.end()){
                    s2.erase(s.substr(i));
                }
            }
        }
        int ans=0;
        for(auto &s:s2){
            ans+=(s.size()+1);
        }
        return ans;
    }
};