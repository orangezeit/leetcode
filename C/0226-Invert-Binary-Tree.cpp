    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        } else {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            if (root->left) {
                root->left = invertTree(root->left);
            }
            if (root->right) {
                root->right = invertTree(root->right);
            }
            return root;
        }
    }
