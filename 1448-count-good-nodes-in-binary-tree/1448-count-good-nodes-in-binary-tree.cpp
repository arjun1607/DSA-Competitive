class Solution {
public:
    int ans=0;
    void dfs(TreeNode *root, int maxi){
        if(root==NULL) return ;
        if(root->val >= maxi) ans++;
        maxi=max(maxi, root->val);
        dfs(root->left, maxi);
        dfs(root->right, maxi);
    }
    int goodNodes(TreeNode* root){
        dfs(root, -1e8);
        return ans;
    }
};