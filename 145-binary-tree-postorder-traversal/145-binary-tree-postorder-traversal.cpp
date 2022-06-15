class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        
        stack<TreeNode*> s;
        TreeNode *curr=root;
        vector<int> ans;
        while(curr!=NULL || !s.empty()){
            if(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }else{
                auto *temp=s.top()->right;
                if(temp==NULL){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && s.top()->right==temp){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    curr=temp;
                }
            }
        }
        return ans;
    }
};