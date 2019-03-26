    void BLN(TreeNode* root, pair<int,int>& target, int level) {
        if (level > target.second) target = {root->val, level};
        if (root->left) BLN(root->left, target, level+1);
        if (root->right) BLN(root->right, target, level+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> target(root->val, 0);
        BLN(root, target, 0);
        return target.first;
    }
