class Solution {
public:
    void recoverTree(TreeNode* root) {
        // Based on Morris Traversal
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* temp = nullptr;
        while (root) {
            if (root->left) {
                TreeNode* prev = root->left;
                while (prev->right && prev->right != root)
                    prev = prev->right;
                if (prev->right == root) {
                    if (temp && temp->val > root->val) {
                        if (!first) first = temp;
                        second = root;
				    }
                    temp = root;
                    root = root->right;
                    prev->right = nullptr;
                } else {
                    prev->right = root;
                    root = root->left;
                }
            } else {
                if (temp && temp->val > root->val) {
                    if (!first) first = temp;
                    second = root;
				}
                temp = root;
                root = root->right;
            }
        }

        swap(first->val, second->val);
    }
};
