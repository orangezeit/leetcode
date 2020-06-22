class Solution {
public:
    void inorderHelper(TreeNode* root, vector<int>& vals) {
        if (root) {
            inorderHelper(root->left, vals);
            vals.push_back(root->val);
            inorderHelper(root->right, vals);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> vals;
        inorderHelper(root, vals);
        int minVal = INT_MAX;

        for (int i = 1; i < vals.size(); ++i) {
            minVal = min(minVal, vals[i] - vals[i-1]);
        }

        return minVal;
    }
};
