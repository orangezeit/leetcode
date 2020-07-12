class BSTIterator {
    stack<TreeNode*> st;
public:
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushLeft(temp->right);
        return temp->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
