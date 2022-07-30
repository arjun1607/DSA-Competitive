class Solution {
public:
    int ans=0;
    void dfs(TreeNode *root, multiset<int> &m){
        if(root==NULL) return ;
        if(m.upper_bound(root->val)==m.end()) ans++;
        m.insert(root->val);
        dfs(root->left, m);
        dfs(root->right, m);
        auto it=m.find(root->val);
        m.erase(it);
    }
    int goodNodes(TreeNode* root) {
        multiset<int> m;
        dfs(root, m);
        return ans;
    }
};