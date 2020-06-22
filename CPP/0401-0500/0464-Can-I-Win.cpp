class Solution {
public:
    vector<int> m;
    bool canWin(int M, int T, int state) {
        if (T <= 0) return false;
        if (m[state]) return m[state] == 1;

        for (int i = 0; i < M; ++i) {
            if (state & (1 << i)) continue;
            if (!canWin(M, T - (i + 1), state | (1 << i)))
                return m[state] = 1;
        }
        m[state] = -1;
        return false;
    }
    bool canIWin(int M, int T) {
        int s = M * (M + 1) / 2;
        if (s < T) return false;
        if (T <= 0) return true;
        m.resize(1 << M);
        return canWin(M, T, 0);
    }
};
