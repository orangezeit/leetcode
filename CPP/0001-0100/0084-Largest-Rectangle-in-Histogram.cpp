class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        stack<int> s;
        int area(0);
        heights.emplace_back(0);

         for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                area = max(area, h * (i - (s.empty() ? 0 : s.top() + 1)));
            }
            s.push(i);
        }

        return area;
    }
};
