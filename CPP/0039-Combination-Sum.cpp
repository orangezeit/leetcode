private:
    vector<vector<int>> sums;
public:
    void sumHelper(vector<int> candidates, int target, int idx, vector<int> sum) {
        if (target == 0) {
            sums.push_back(sum);
        } else {
            for (int i = idx; i < candidates.size(); ++i) {
                if (target < candidates[i]) {
                    break;
                }
                sum.push_back(candidates[i]);
                sumHelper(candidates, target - candidates[i], i, sum);
                sum.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sum;
        sort(candidates.begin(), candidates.end());
        sumHelper(candidates, target, 0, sum);
        return sums;
    }
