    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (val > root->val) {
            if (!root->right) {
                root->right = new TreeNode(val);
            } else {
                root->right = insertIntoBST(root->right, val);
            }
        } else {
            if (!root->left) {
                root->left = new TreeNode(val);
            } else {
                root->left = insertIntoBST(root->left, val);
            }
        }
        
        return root;
    }
