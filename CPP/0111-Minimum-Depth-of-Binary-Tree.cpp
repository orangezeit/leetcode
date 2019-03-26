    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else if (!root->left) {
            return minDepth(root->right)+1;
        } else if (!root->right) {
            return minDepth(root->left)+1;
        } else {
            return min(minDepth(root->left)+1, minDepth(root->right)+1);
        }
    }
