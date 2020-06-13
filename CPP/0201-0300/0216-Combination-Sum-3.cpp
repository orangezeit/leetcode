private:
    vector<vector<int>> sets;
public:
    void setHelper(vector<int> set, int n, int k, int lowerbound, int upperbound) {
        if (n == 0 && k == 0) {
            sets.push_back(set);
        } else {
            for (int i = lowerbound; i <= upperbound; ++i) {
                if (n < i || k < 0) {
                    break;
                }
                set.push_back(i);
                setHelper(set, n-i, k-1, i+1, min(n-i-(k-2)*(k-1)/2,9));
                set.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> set;
        setHelper(set, n, k, 1, min(n-k*(k-1)/2, 9));
        return sets;
    }
