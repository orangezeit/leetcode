class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

        for (int i = 1; i < A.size(); ++i) {
            pq.push({(double)A[0] / A[i], {0, i}});
        }

        pair<int, int> ans;

        while (K--) {
            ans = pq.top().second;
            //cout << ans.first << " " << ans.second << endl;
            pq.pop();
            if (ans.first + 1 < ans.second) {
                //cout << "e" << endl;
                pq.push({(double)A[ans.first + 1] / A[ans.second], {ans.first + 1, ans.second}});
            }
        }

        return {A[ans.first], A[ans.second]};
    }
};
