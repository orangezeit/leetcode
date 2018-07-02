private:
    vector<vector<int>> sums;
public:
    void sumHelper(vector<int> candidates, int target, int idx, vector<int> sum) {
        if (target == 0) {
            if (find(sums.begin(), sums.end(), sum) == sums.end()) {
                sums.push_back(sum);
            }
        } else {
            for (int i = idx; i < candidates.size(); ++i) {
                if (target < candidates[i]) {
                    break;
                }
                int k = candidates[i];
                sum.push_back(candidates[i]);
                candidates.erase(candidates.begin()+i);
                sumHelper(candidates, target - k, i, sum);
                candidates.insert(candidates.begin()+i, sum.back());
                sum.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sum;
        sort(candidates.begin(), candidates.end());
        sumHelper(candidates, target, 0, sum);
        return sums;
    }
