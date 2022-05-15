/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int sum(TreeNode *root, int d){
        if(root==NULL) return 0;
        if(d==1) return root->val;
        return sum(root->left, d-1)+sum(root->right, d-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int d=height(root);
        cout<<d;
        return sum(root, d);       
    }
};