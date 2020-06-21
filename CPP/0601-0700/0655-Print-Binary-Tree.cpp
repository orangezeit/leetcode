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
    void record(TreeNode* root, int level, int& max) {
        bool hasLeft = false;

        if (root->left != NULL) {
            hasLeft = true;
            level++;

            if (root->left->left == NULL && root->left->right == NULL && level > max) {
                max = level;
            }

            record(root->left, level, max);
        }

        if (root->right != NULL) {
            if (!hasLeft) {
                level++;
            }

            if (root->right->left == NULL && root->right->right == NULL && level > max) {
                max = level;
            }

            record(root->right, level, max);
        }

    }

    void input (TreeNode* root, int level, vector<vector<string>>& print, int len, int move) {
        move /= 2;
        bool hasLeft = false;

        if (root->left != NULL) {
            hasLeft = true;
            level++;

            print[level][len - move] = to_string(root->left->val);

            input(root->left, level, print, len - move, move);
        }

        if (root->right != NULL) {
            if (!hasLeft) {
                level++;
            }

            print[level][len + move] = to_string(root->right->val);

            input(root->right, level, print, len + move, move);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int level = 1;
        int max = 1;

        record(root, level, max);
        //cout << max;
        int len = pow(2,max)-1;

        vector<vector<string>> print(max, vector<string>(len));

        len /= 2;
        int move = len+1;
        print[0][len] = to_string(root->val);
        level = 0;
        input(root, level, print, len, move);

        return print;
    }
};
