private:
    vector<vector<int>> paths;
    void findPath(TreeNode* root, int sum, vector<int> path) {
        if (!root->left && !root->right) {
            if (root->val == sum) {
                paths.push_back(path);
            }
        }
        
        if (root->left) {
            path.push_back(root->left->val);
            findPath(root->left, sum - root->val, path);
            path.pop_back();
        }
            
        if (root->right){
            path.push_back(root->right->val);
            findPath(root->right, sum - root->val, path);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root) {
            findPath(root, sum, {root->val});
        }
        
        return paths;
    }
