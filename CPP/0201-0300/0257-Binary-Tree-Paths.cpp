    void record(TreeNode* root, vector<string>& set, string temp) {
        if (root->left && root->right) {
            record(root->left, set, temp + "->" + to_string(root->left->val));
            record(root->right, set, temp + "->" + to_string(root->right->val));
        } else if (root->left) {
            record(root->left, set, temp + "->" + to_string(root->left->val));
        } else if (root->right) {
            record(root->right, set, temp + "->" + to_string(root->right->val));
        } else {
            set.push_back(temp);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> set;
        
        if (root) {
            record(root, set, to_string(root->val));
        }
        
        return set;
    }
