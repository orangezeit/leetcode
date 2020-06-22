class Solution {
public:
    bool concave(const vector<int>& O, const vector<int>& A, const vector<int>& B) {
        return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]) < 0;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if (points.size() <= 3) return points;

        vector<vector<int>> upper, lower;
        sort(points.begin(), points.end());

        for (const vector<int>& p: points) {
            while (upper.size() > 1 && concave(upper[upper.size() - 2], upper.back(), p))
                upper.pop_back();
            upper.push_back(p);
        }
        upper.pop_back();

        reverse(points.begin(), points.end());
        for (const vector<int>& p: points) {
            while (lower.size() > 1 && concave(lower[lower.size() - 2], lower.back(), p))
                lower.pop_back();
            lower.push_back(p);
        }
        lower.pop_back();

        upper.insert(upper.end(), lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        upper.erase(unique(upper.begin(), upper.end()), upper.end());
        return upper;
    }
};
