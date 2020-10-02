class Solution {
public:
    TreeNode* findNeartestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                auto r = q.front();
                q.pop();
                if (r == u) return i == s - 1 ? nullptr : q.front();
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
        }
        return nullptr;
    }
};
