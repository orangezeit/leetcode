    TreeNode* buildTree(vector<int> nums, int i, int j) {
        if (i > j) {
            return NULL;
        }
        
        TreeNode* t = new TreeNode(nums[(i+j)/2]);
        t->left = buildTree(nums, i, (i+j)/2-1);
        t->right = buildTree(nums, (i+j)/2+1, j);
        return t;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
