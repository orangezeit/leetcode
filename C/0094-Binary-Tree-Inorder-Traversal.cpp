    void inorderHelper(TreeNode* root, vector<int>& vals) {
        if (root != NULL) {
            inorderHelper(root->left, vals);
            vals.push_back(root->val);
            inorderHelper(root->right, vals);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        inorderHelper(root, vals);
        return vals;
    }
