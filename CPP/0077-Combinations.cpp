private:
    vector<vector<int>> combinations;
public:
    void combineHelper(int n, int k, int idx, vector<int> combination) {
        if (k == 0) {
            combinations.push_back(combination);
        } else {
            for (int i = idx; i <= n; ++i) {
                combination.push_back(i);
                combineHelper(n, k-1, i+1, combination);
                combination.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        combineHelper(n, k, 1, combination);
        return combinations;
    }
