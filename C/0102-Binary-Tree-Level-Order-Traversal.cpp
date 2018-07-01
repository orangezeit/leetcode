private:
    vector<vector<int>> orders;
    
    void record(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        
        if (orders.size() == level) {
            orders.push_back({root->val});
        } else {
            orders[level].push_back(root->val);
        }
        
        if (root->left) {
            record(root->left, level+1);
        } 
        
        if (root->right) {
            record(root->right, level+1);
        }
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        record(root, 0);
        return orders;
    }
