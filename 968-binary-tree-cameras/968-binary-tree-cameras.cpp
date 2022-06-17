class Solution {
public:
    int cameras=0;
    int helper(TreeNode* root){
        if(root==NULL) return 3;;
        int x=helper(root->left);
        int y=helper(root->right);
        if(x==1 || y==1) { cameras++; return 2; }
        else if(x==2 || y==2) return 3;;
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        int n=helper(root);
        if(n==1) cameras++;
        return cameras;
    }
};