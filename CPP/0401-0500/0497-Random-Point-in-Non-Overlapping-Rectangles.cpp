class Solution {
public:
    vector<int> probs;
    vector<vector<int>>* rc;

    Solution(vector<vector<int>>& rects) {
        rc = &rects;
        probs.resize(rects.size());

        for (int i = 0; i < rects.size(); ++i) {
            probs[i] = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            if (i) probs[i] += probs[i - 1];
        }
    }

    vector<int> pick() {
        int n = probs.back();
        int r = rand() % n;
        int ub = upper_bound(probs.begin(), probs.end(), r) - probs.begin();
        int x = (*rc)[ub][0] + rand() % ((*rc)[ub][2] - (*rc)[ub][0] + 1);
        int y = (*rc)[ub][1] + rand() % ((*rc)[ub][3] - (*rc)[ub][1] + 1);
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
