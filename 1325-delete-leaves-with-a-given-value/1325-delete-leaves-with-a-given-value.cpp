
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        
        TreeNode *l = removeLeafNodes(root->left, target);
        TreeNode *r = removeLeafNodes(root->right, target);
        
        if(l==NULL && r==NULL && root->val==target){
            return NULL;
        }
        
        root->left = l;
        root->right = r;
        
        return root;
    }
};