class Solution {
public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder,
                        int preleft=0, int preright=INT_MAX, int inleft=0, int inright=INT_MAX) {
        if (preright == INT_MAX) preright = inright = preorder.size();

        for (int i = inleft; i < inright; ++i)
            if (inorder[i] == preorder[preleft])
                return new TreeNode(preorder[preleft],
                                    buildTree(preorder, inorder, preleft + 1, preleft + i - inleft + 1, inleft, i),
                                    buildTree(preorder, inorder, preleft + i - inleft + 1, preright, i + 1, inright));
        return nullptr;
    }
};
