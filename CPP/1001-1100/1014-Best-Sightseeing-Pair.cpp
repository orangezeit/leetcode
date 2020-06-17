class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        priority_queue<int> pq;
        int ans(-1);
        for (int i = 1; i < A.size(); ++i) {
            pq.push(A[i-1] - (A.size() - i));
            ans = max(ans, A[i] + pq.top() + (int)A.size() - i - 1);
        }
        return ans;
    }
};
