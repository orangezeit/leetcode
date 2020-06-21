class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const auto& a, const auto& b){ return a[1] < b[1] || a[1] == b[1] && a[0] < b[0]; });
        int t(0), ans(0);
        priority_queue<int> pq;
        for (const auto& c: courses) {
            t += c[0];
            pq.push(c[0]);
            if (t > c[1]) {
                t -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
