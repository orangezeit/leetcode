class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int z(0);
        map<int, int> p, n;
        for (const int& i: A) i > 0 ? p[i]++ : i < 0 ? n[-i]++ : z++;
        if (z % 2) return false;
        for (auto& [k, v]: p) {
            if (p.count(2 * k) && p[2 * k] >= v) {
                p[2 * k] -= v;
            } else if (v) {
                return false;
            }
        }
        for (auto& [k, v]: n) {
            if (n.count(2 * k) && n[2 * k] >= v) {
                n[2 * k] -= v;
            } else if (v) {
                return false;
            }
        }
        return true;
    }
};
