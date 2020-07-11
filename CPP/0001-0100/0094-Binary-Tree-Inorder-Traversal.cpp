/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    // 1. Recursive
    vector<int> inorderTraversal(TreeNode* root) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* rt) {
            if (!root) return;
            dfs(rt->left);
            ans.emplace_back(rt->val);
            dfs(rt->right);
        };
        dfs(root);
        return vals;
    }
};

class Solution {
public:
    // 2. Iterative
    vector<int> inorderTraversal(TreeNode* root) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        stack<TreeNode*> st;
        vector<int> ans;
        while (root || !st.empty())
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                ans.emplace_back(st.top()->val);
                root = st.top()->right;
                st.pop();
            }
        return ans;
    }
};

class Solution {
public:
    // 3. Morris
    vector<int> inorderTraversal(TreeNode* root) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        vector<int> ans;
        while (root) {
            if (root->left) {
                TreeNode* prev = root->left;
                while (prev->right && prev->right != root)
                    prev = prev->right;
                if (prev->right == root) {
                    ans.emplace_back(root->val);
                    root = root->right;
                    prev->right = nullptr;
                } else {
                    prev->right = root;
                    root = root->left;
                }
            } else {
                ans.emplace_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};
