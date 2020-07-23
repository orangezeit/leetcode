class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                        int inleft=0, int inright=INT_MAX, int postleft=0, int postright=INT_MAX) {
        if (postright == INT_MAX) inright = postright = postorder.size();

        for (int i = inleft; i < inright; ++i)
            if (inorder[i] == postorder[postright - 1])
                return new TreeNode(postorder[postright - 1],
                                    buildTree(inorder, postorder, inleft, i, postleft, postleft + i - inleft),
                                    buildTree(inorder, postorder, i + 1, inright, postleft + i - inleft, postright - 1));
        return nullptr;
    }
};
