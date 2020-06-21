class Solution {
public:
    unordered_map<int, int> m;
    int M;
    Solution(int N, vector<int>& blacklist) {
        M = N - blacklist.size();
        for (const int& b: blacklist) m[b] = -1;

        int k = N - 1;
        for (auto& p: m) {
            if (p.first >= M) continue;
            while (m.count(k)) k--;
            p.second = k--;
        }

    }

    int pick() {
        int i = rand() % M;
        return m.count(i) ? m[i] : i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
