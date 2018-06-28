    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // traverse all nodes and record them to see if anywhere is not ordered
    
    void inorderHelper(TreeNode* root, vector<int>& vals) {
        if (root != NULL) {
            inorderHelper(root->left, vals);
            vals.push_back(root->val);
            inorderHelper(root->right, vals);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else if (root->left == NULL && root->right == NULL) {
            return true;
        }
        
        vector<int> vals;
        inorderHelper(root, vals);
        
        for (int i = 0; i < vals.size()-1; ++i) {
            if (vals[i] >= vals[i+1]) {
                return false;
            }
        }
        
        return true;
    }
