class Solution {
public:
    bool isValidBST(TreeNode* root, long l=INT_MIN, long r=INT_MAX) {
        if(root==NULL) return true;
        if(root->val >= l && root->val <= r){
            return isValidBST(root->left, l, root->val-1L) && isValidBST(root->right, root->val+1L, r);
        }
        return false;
    }
};