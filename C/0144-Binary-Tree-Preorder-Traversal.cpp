    void preorderHelper(TreeNode* root, vector<int>& vals) {
        if (root != NULL) {
            vals.push_back(root->val);
            preorderHelper(root->left, vals);
            preorderHelper(root->right, vals);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals;
        preorderHelper(root, vals);
        return vals;
    }
