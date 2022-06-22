class Node{
    public:
    Node* links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    private: Node* root = new Node();
    public:
    void insert(int num){
        Node *node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }
    
    int getMax(int num){
        Node *node = root;
        int maxi = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit)){
                maxi = maxi | (1<<i);
                node = node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ;
        for(int i=0;i<q.size();i++){
            oQ.push_back({q[i][1], {q[i][0], i}});
        }
        sort(oQ.begin(), oQ.end());
        vector<int> ans(q.size());
        int k=0;
        Trie trie;
        for(int i=0;i<q.size();i++){
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qidx = oQ[i].second.second;
            while(k<nums.size() && nums[k] <= ai){
                trie.insert(nums[k]);
                k++;
            }
            if(k==0) ans[qidx]=-1;
            else{
                int temp = trie.getMax(xi);
                ans[qidx] = temp;
            }
        }
        return ans;
    }
};