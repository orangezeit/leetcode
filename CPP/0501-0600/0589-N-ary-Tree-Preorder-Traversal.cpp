    void preorderHelper(Node* root, vector<int>& pre) {
        if (!root) {
            return;
        }
        pre.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            preorderHelper(root->children[i], pre);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> pre;
        preorderHelper(root, pre);
        return pre;
    }
