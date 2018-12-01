    int leaves(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL) {
            return -1;
        } else {
            int loc = max(leaves(root->right, ans), leaves(root->left, ans)) + 1;
            
            loc == ans.size() ? ans.push_back({root->val}) : ans[loc].push_back(root->val);
            
            return loc;
        }
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        leaves(root, ans);
        return ans;
    }
