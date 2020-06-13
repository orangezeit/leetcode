class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const int& b: blocks) pq.push(b);
        while (pq.size() > 1) {
            pq.pop();
            pq.push(pq.top() + split);
            pq.pop();
        }
        return pq.top();
    }
};
