class Solution {
public:
    vector<TreeNode*> buildTree(int left, int right) {
        if (left > right) return {nullptr};

        vector<TreeNode*> ans;

        for (int i = left; i <= right; ++i) {
            vector<TreeNode*> lb = buildTree(left, i - 1);
            vector<TreeNode*> rb = buildTree(i + 1, right);
            for (TreeNode* ltn: lb)
                for (TreeNode* rtn: rb) {
                    TreeNode* tn = new TreeNode(i);
                    tn->left = ltn;
                    tn->right = rtn;
                    ans.emplace_back(tn);
                }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return n ? buildTree(1, n) : vector<TreeNode*>();
    }
};
