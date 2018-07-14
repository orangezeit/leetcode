    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return NULL;
        }
        
        if (root->val == val) {
            return root;
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
