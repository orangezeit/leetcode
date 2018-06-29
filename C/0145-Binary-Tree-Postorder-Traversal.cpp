    void postorderHelper(TreeNode* root, vector<int>& vals) {
        if (root != NULL) {
            postorderHelper(root->left, vals);
            postorderHelper(root->right, vals);
            vals.push_back(root->val);
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        postorderHelper(root, vals);
        return vals;
    }
