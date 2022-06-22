class Node{
    public :
    Node *links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node *node){
        links[bit] = node;
    }
};
class Trie{
    private : Node *root = new Node();
    public:
    void insert(int num){
        Node *node = root;
        for(int i=31; i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num){
        Node *node = root;
        int maxnum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxnum = maxnum | (1<<i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxnum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // if we are able to set the bits from the lest, the number will be more
        // bitwise we'll try to eliminate numbers
        // if opposite bit does not exist we r bound to find same bit 
        // it has to be there becoz trie has all the 32 bits and options are only 2 - 0/1
        Trie trie;
        for(auto &x:nums){
            trie.insert(x);
        }
        int maxi=0;
        for(auto &x:nums){
            maxi = max(maxi, trie.getMax(x));
        }
        return maxi;
    }
};