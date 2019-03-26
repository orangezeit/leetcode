private:
    unordered_map<int, int> record;
public:
    int add(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        root->val += add(root->left) + add(root->right);
        record[root->val]++;
        return root->val;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        add(root);
        
        unordered_set<int> res;
        int freq = 0;
        
        for (auto it = record.begin(); it != record.end(); ++it) {
            if (it->second > freq) {
                res.clear();
                res.insert(it->first);
                freq = it->second;
            } else if (it->second == freq) {
                res.insert(it->first);
            }
        }
        
        return vector<int>(res.begin(), res.end());
    }
