class Solution {
public:
    bool differByOne(vector<string>& dict) {
        // self-defined hash, mod 10000001723, any big prime fine
        // strict, check if there is hash clashing

        long mod(10000001723), m(dict[0].length());
        vector<long> mod_pows(m);
        mod_pows[0] = 1;
        for (int i = 1; i < m; ++i)
            mod_pows[i] = mod_pows[i - 1] * 27 % mod;

        unordered_map<long, vector<long>> hs;

        for (int k = 0; k < dict.size(); ++k) {
            long h = 0;
            for (char& c: dict[k])
                h = (27 * h + c - 'a' + 1) % mod;
            for (int i = 0; i < m; ++i) {
                long t = (h - mod_pows[m - i - 1] * (dict[k][i] - 'a' + 1) % mod + mod) % mod;
                if (hs.count(t)) {
                    for (const long& x: hs[t]) {
                        int kk(x / m), ii(x % m);
                        if (ii == i) {
                            bool checked = true;
                            for (int p = 0; p < m; ++p) {
                                if (p == i) continue;
                                if (dict[k][p] != dict[kk][p]) {
                                    break;
                                    checked = false;
                                }
                            }
                            if (checked) return true;
                        }
                    }
                }
                hs[t].emplace_back(m * k + i);
            }
        }

        return false;
    }
};
