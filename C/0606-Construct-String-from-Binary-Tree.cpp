    string tree2str(TreeNode* t) {

        if (t == NULL) {
            return "";
        } else {
            if (t->left == NULL && t->right == NULL) {
                return to_string(t->val);
            } else if (t->left == NULL) {
                return to_string(t->val) + "()(" + tree2str(t->right) + ")";
            } else if (t->right == NULL) {
                return to_string(t->val) + "(" + tree2str(t->left) + ")";
            } else {
                return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
            }
            
        }
    }
