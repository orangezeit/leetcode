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
    void record(TreeNode* root, vector<vector<int>>& orders, int level, int idx) {
        level++;



        if (root->left != NULL) {

            orders.push_back({level-1, 2*idx});

            record(root->left, orders, level, 2 * idx);
        }

        if (root->right != NULL) {

            orders.push_back({level-1, 2*idx+1});

            record(root->right, orders, level, 2 * idx + 1);
        }

    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<vector<int>> orders;

        if (root == NULL) {
            return 0;
        }

        vector<int> firstLevel(1, 1);
        orders.push_back({0,0});

        int level = 1;

        record(root, orders, level, 0);

        if (orders.size() == 1) {
            return 1;
        }

        sort(orders.begin(), orders.end());

        int maxWidth = 1;
        int start = 0;
        int end = 0;

        for (int i = 0; i < orders.size()-1; ++i) {
            if(orders[i][0] != orders[i+1][0]) {
                end = orders[i][1];
                if (maxWidth < end - start + 1) {
                    maxWidth = end - start + 1;
                }
                start = orders[i+1][1];
            }
        }

        end = orders[orders.size()-1][1];
        if (maxWidth < end - start + 1) {
            maxWidth = end - start + 1;
        }

        return maxWidth;
    }
};
