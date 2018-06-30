    void add(TreeNode* root, int& sum) {
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            }
            add(root->left, sum);
        }
        
        if (root->right) {
            add(root->right, sum);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int sum(0);
            add(root, sum);
            return sum;
        }
    }
