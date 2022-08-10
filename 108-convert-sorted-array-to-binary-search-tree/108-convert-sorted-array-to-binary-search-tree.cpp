class Solution {
public:
    TreeNode* helper(int i, int j, vector<int> &nums){
        if(i>j) return NULL;
        int mid = i+(j-i)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(i, mid-1, nums);
        root->right = helper(mid+1, j, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(0, n-1, nums);
    }
};