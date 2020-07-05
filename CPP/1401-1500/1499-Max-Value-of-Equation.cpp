class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> dq;
        int ans(-1e9);
        for (int i = 0; i < points.size(); ++i) {
            while (!dq.empty() && points[i][0] - points[dq.front()][0] > k) dq.pop_front();
            if (!dq.empty()) ans = max(ans, points[dq.front()][1] - points[dq.front()][0] + points[i][1] + points[i][0]);
            while (!dq.empty() && points[dq.back()][1] - points[dq.back()][0] <= points[i][1] - points[i][0]) dq.pop_back();
            dq.push_back(i);
        }
        return ans;
    }
};
