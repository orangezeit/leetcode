class Solution {
public:
    TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
        // Time Complexity: O(N)
        // Space Complexity: O(lg N)
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (prev && prev->val >= root->val) return false;
        prev = root;
        return isValidBST(root->right);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* minNode=nullptr, TreeNode* maxNode=nullptr) {
        // Time Complexity: O(N)
        // Space Complexity: O(lg N)
        if (!root) return false;
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val) return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};
