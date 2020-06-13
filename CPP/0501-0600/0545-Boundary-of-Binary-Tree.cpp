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
    void leftView(TreeNode* root, int level, vector<TreeNode*>& views) {
        if (!root) return;
        if (level == views.size()) views.push_back(root);
        leftView(root->left, level + 1, views);
        leftView(root->right, level + 1, views);

    }
    void bottomView(TreeNode* root, vector<TreeNode*>& views) {
        if (!root) return;
        if (!root->left && !root->right) views.push_back(root);
        bottomView(root->left, views);
        bottomView(root->right, views);
    }
    void rightView(TreeNode* root, int level, vector<TreeNode*>& views) {
        if (!root) return;
        if (level == views.size()) views.push_back(root);
        rightView(root->right, level + 1, views);
        rightView(root->left, level + 1, views);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<TreeNode*> leftViews, bottomViews, rightViews;
        if (!root) return {};
        vector<TreeNode*> start = {root};

        leftView(root->left, 0, leftViews);
        bottomView(root->left, bottomViews);
        bottomView(root->right, bottomViews);
        rightView(root->right, 0, rightViews);

        if (leftViews.size()) {
            int k = leftViews.size();
            while (leftViews[--k] != bottomViews[0]) {}
            //cout << k << endl;
            start.insert(start.end(), leftViews.begin(), leftViews.begin() + k);
        }
        start.insert(start.end(), bottomViews.begin(), bottomViews.end());


        if (rightViews.size()) {
            reverse(rightViews.begin(), rightViews.end());
            int k = 0;
            while (rightViews[k++] != bottomViews.back()) {}
            start.insert(start.end(), rightViews.begin() + k, rightViews.end());
        }
        vector<int> v(start.size());
        for (int i = 0; i < start.size(); ++i)
            v[i] = start[i]->val;
        return v;
    }
};
