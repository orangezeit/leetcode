    TreeNode* invert(TreeNode* root) {
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        if (root->left) {
            root->left = invert(root->left);
        }
        
        if (root->right) {
            root->right = invert(root->right);
        }
        
        return root;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }
        
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
    bool isSymmetric(TreeNode* root) {

        if (!root) {
            return true;
        } else if (!root->left && !root->right) {
            return true;
        } else if (!root->left || !root->right) {
            return false;
        } else {
            return isSameTree(root->left, invert(root->right));
        }
        
    }
