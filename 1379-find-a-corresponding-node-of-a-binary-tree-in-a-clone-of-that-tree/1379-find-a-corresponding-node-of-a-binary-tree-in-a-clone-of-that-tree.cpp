/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* org, TreeNode* clone, TreeNode* k) {
        queue<TreeNode*> q1, q2;
        q1.push(org);
        q2.push(clone);
        while(!q1.empty()){
            auto t1=q1.front();
            auto t2=q2.front();
            q1.pop(); q2.pop();
            if(t1==k) return t2;
            if(t1->left) q1.push(t1->left);
            if(t1->right) q1.push(t1->right);
            if(t2->left) q2.push(t2->left);
            if(t2->right) q2.push(t2->right);
        }
        return NULL;
    }
};