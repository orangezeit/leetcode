class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int pts(0), s(0);
        for (int i = 0; i < k; ++i)
            s += calories[i];
        s > upper ? pts++ : s < lower ? pts-- : pts;
        for (int i = k; i < calories.size(); ++i) {
            s += calories[i] - calories[i-k];
            s > upper ? pts++ : s < lower ? pts-- : pts;
        }
        return pts;
    }
};
