    void leafCollection(TreeNode* root, vector<int>& record) {
        if (!root) {
            return;
        }
        
        if (!root->left && !root->right) {
            record.push_back(root->val);
        }
        
        leafCollection(root->left, record);
        leafCollection(root->right, record);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> record1, record2;
        
        leafCollection(root1, record1);
        leafCollection(root2, record2);
        
        return record1 == record2;
    }
