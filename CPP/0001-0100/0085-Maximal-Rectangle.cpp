class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m(matrix.size()), n(matrix[0].size());
        int heights[n + 1] = {};
        int area(0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            stack<int> s;
            int temp(0);

            for (int i = 0; i <= n; ++i) {
                while (!s.empty() && heights[s.top()] > heights[i]) {
                    int h = heights[s.top()];
                    s.pop();
                    area = max(area, h * (i - (s.empty() ? 0 : s.top() + 1)));
                }
                s.push(i);
            }
            area = max(area, temp);
        }

        return area;
    }
};
