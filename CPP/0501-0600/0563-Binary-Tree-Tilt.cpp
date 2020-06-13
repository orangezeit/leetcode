    int add(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        root->val += add(root->left) + add(root->right);
        return root->val;
    }
    
    void diff(TreeNode* root, int& d) {
        if (!root) {
            return;
        }
        
        int l(0), r(0);
        
        if (root->left) {
            l = root->left->val;
            diff(root->left, d);
        }
        
        if (root->right) {
            r = root->right->val;
            diff(root->right, d);
        }
        
        d += abs(l - r);
    }
    
    int findTilt(TreeNode* root) {
        add(root);
        int d = 0;
        diff(root, d);
        return d;
    }
