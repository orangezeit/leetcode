class Solution {
public:
    int trap(vector<int>& height) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        stack<int> s;
        int curr(0);
        int res(0);

        while (curr < height.size()) {
            while (!s.empty() && height[s.top()] < height[curr]) {
                int top = s.top();
                s.pop();
                if (s.empty()) break;
                int h = min(height[curr], height[s.top()]) - height[top];
                int dist = curr - s.top() - 1;
                res += h * dist;
            }
            s.push(curr++);
        }

        return res;
    }
};
