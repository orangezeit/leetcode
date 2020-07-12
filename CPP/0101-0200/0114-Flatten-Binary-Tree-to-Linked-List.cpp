class Solution {
public:
    TreeNode* temp = nullptr;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = temp;
        root->left = nullptr;
        temp = root;
    }
};
