class Solution {
public:
    // preorder => root left right
    // inorder => left root right
    // ridx-is = X - (ps+1) 
    unordered_map<int,int> m;
    TreeNode* helper(vector<int> &pre, int ps, int pe, vector<int> &in, int is, int ie){
        if(is>ie || ps>pe) return NULL;
        TreeNode* root=new TreeNode(pre[ps]);
        int ridx=m[pre[ps]];
        root->left=helper(pre,ps+1,ridx-is+ps,in,is,ridx-1);
        root->right=helper(pre,ridx-is+ps+1,pe,in,ridx+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=in.size()-1;
        for(int i=0;i<=n;i++) m[in[i]]=i;
        return helper(pre,0,n,in,0,n);
    }
};