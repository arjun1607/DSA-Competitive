class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; 
        if(root==NULL) return ans;
        
        TreeNode *node=root;
        stack<TreeNode*> s;
        while(true){
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }else{
                if(s.empty()) break;
                auto t=s.top();
                s.pop();
                ans.push_back(t->val);
                node=t->right;
            }
        }
        return ans;
    }
};