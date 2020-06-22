class Solution {
private:
    unordered_set<int> record;

    int n, c;
public:
    Solution(int n_rows, int n_cols) {
        c = n_cols;
        n = n_rows * n_cols;
    }

    vector<int> flip() {
        int k;

        do {
            k = rand() % n;
        } while (record.find(k) != record.end());

        record.insert(k);
        return {k / c, k % c};
    }

    void reset() {
        record.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
