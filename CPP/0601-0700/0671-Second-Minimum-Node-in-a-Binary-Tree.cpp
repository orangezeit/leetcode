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
public:

    void traverseToFindSecondMin(TreeNode* root, pair<int, int>& smallests) {
        if (!root) return;
        if (smallests.second == -1) {
            smallests.second = root->val;
        } else if (smallests.first == -1) {
            if (root->val < smallests.second) {
                smallests.first = smallests.second;
                smallests.second = root->val;
            } else if (root->val > smallests.second) {
                smallests.first = root->val;
            }
        } else if (root->val < smallests.second) {
            smallests.first = smallests.second;
            smallests.second = root->val;
        } else if (root->val < smallests.first && root->val > smallests.second) {
            smallests.first = root->val;
        }

        traverseToFindSecondMin(root->left, smallests);
        traverseToFindSecondMin(root->right, smallests);
    }

    int findSecondMinimumValue(TreeNode* root) {
        pair<int, int> two(-1, -1);
        traverseToFindSecondMin(root, two);
        return two.first;
    }
};
