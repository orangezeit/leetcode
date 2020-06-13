class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int ans(0);
        while (pq.size() > 1) {
            int s1(pq.top());
            pq.pop();
            int s2(pq.top());
            pq.pop();
            pq.push(s1 + s2);
            ans += s1 + s2;
        }
        return ans;
    }
};
