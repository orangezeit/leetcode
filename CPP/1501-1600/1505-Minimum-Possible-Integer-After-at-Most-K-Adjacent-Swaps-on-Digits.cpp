struct Fenwick {
    vector<int> sums;
    Fenwick(int n) : sums(n + 1) {}
    void update(int k, int delta) {
        for (int i = k + 1; i < sums.size(); i += i & -i)
            sums[i] += delta;
    }
    int query(int k) {
        int ans(0);
        for (int i = k + 1; i > 0; i -= i & -i)
            ans += sums[i];
        return ans;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        // Time Complexity: O(N lg N)
        // Space Complexity: O(N)
        const int n(num.length());
        array<queue<int>, 10> pos;
        for (int i = 0; i < n; ++i) {
            pos[num[i] - '0'].push(i);
        }
        Fenwick tree(n);
        vector<int> used(n);
        string ans;
        while (k > 0 && ans.length() < n) {
            for (int d = 0; d < 10; ++d) {
                if (pos[d].empty()) continue;
                const int i = pos[d].front();
                const int cost = i - tree.query(i - 1);
                if (cost > k) continue;
                k -= cost;
                ans += '0' + d;
                tree.update(i, 1);
                used[i] = true;
                pos[d].pop();
                break;
            }
        }
        for (int i = 0; i < n; ++i) if (!used[i]) ans += num[i];
        return ans;
    }
};
