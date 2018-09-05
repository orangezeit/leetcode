    void inorderHelper(TreeNode* root, vector<int>& vals) {
        if (root) {
            inorderHelper(root->left, vals);
            vals.push_back(root->val);
            inorderHelper(root->right, vals);
        }
    }
    
    TreeNode* buildBST(vector<int> vals) {
        if (vals.empty()) {
            return NULL;
        } else {
            TreeNode* t = new TreeNode(vals[0]);
            t->right = buildBST(vector<int>(vals.begin() + 1, vals.end()));
            return t;
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vals;
        inorderHelper(root, vals);
        return buildBST(vals);
    }
