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
    void traverse(TreeNode* tn, const unordered_set<int>& del_nodes, queue<TreeNode*>& q) {
        if (tn->left) {
            if (del_nodes.find(tn->left->val) != del_nodes.end()) {
                if (tn->left->left) q.push(tn->left->left);
                if (tn->left->right) q.push(tn->left->right);
                tn->left = nullptr;
            } else {
                traverse(tn->left, del_nodes, q);
            }
        }

        if (tn->right) {
            if (del_nodes.find(tn->right->val) != del_nodes.end()) {
                if (tn->right->left) q.push(tn->right->left);
                if (tn->right->right) q.push(tn->right->right);
                tn->right = nullptr;
            } else {
                traverse(tn->right, del_nodes, q);
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        queue<TreeNode*> q({root});
        unordered_set<int> del_nodes(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        while (!q.empty()) {
            if (del_nodes.find(q.front()->val) != del_nodes.end()) {
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
            } else {
                traverse(q.front(), del_nodes, q);
                ans.push_back(q.front());
            }
            q.pop();
        }

        return ans;
    }
};
