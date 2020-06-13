/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_set<int> rec;
    int zeroes = 0;
    int helper(TreeNode* root) {
        if (root) {
            int temp = root->val + helper(root->left) + helper(root->right);
            if (temp == 0) zeroes++;
            rec.insert(temp);
            return temp;
        } else {
            return 0;
        }
    }

public:
    bool checkEqualTree(TreeNode* root) {
        int total = helper(root);
        return total ? !(total % 2) && rec.find(total / 2) != rec.end() : zeroes > 1;
    }
};
