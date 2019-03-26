    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        
        int d = 1;
        
        for (int i = 0; i < root->children.size(); ++i) {
            d = max(d, maxDepth(root->children[i]) + 1);
        }
        
        return d;
    }
