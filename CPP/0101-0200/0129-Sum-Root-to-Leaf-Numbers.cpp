    void record(TreeNode* root, int& sum, string str) {
        if (root == NULL) {
            sum += stoi(str);
            return;
        }
        
        str += to_string(root->val);
        record(root->left, sum, str);
        record(root->right, sum, str);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        record(root, sum, "");
        return sum / 2;
    }
