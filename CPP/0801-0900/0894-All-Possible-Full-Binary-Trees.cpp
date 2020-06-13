    unordered_map<int, vector<TreeNode*>> memo;
    
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> record;
        
        if (N % 2 == 0) return record;
        
        if (N == 1) {
            record.push_back(new TreeNode(0));
        } else {
            for (int i = 1; i < N; i += 2) {
                if (memo.find(i) == memo.end())
                    memo[i] = allPossibleFBT(i);
                if (memo.find(N - i - 1) == memo.end())
                    memo[N - i - 1] = allPossibleFBT(N - i - 1);
                
                vector<TreeNode*> leftFBT = memo[i];
                vector<TreeNode*> rightFBT = memo[N - i - 1];
                
                for (int j = 0; j < leftFBT.size(); ++j) {
                    for (int k = 0; k < rightFBT.size(); ++k) {
                        TreeNode* t = new TreeNode(0);
                        t->left = leftFBT[j];
                        t->right = rightFBT[k];
                        record.push_back(t);
                    }
                }
            }
        }
        
        return record;
    }
