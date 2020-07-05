class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        sort(wd.begin(), wd.end());
        unordered_map<int, bool> record;
        function<bool(int)> helper = [&](int k) {
            if (k == s.length()) return true;
            if (record.count(k)) return record[k];
            string str;
            bool f(false);
            for (int i = k; i < s.length(); ++i) {
                str += s[i];
                auto it = lower_bound(wd.begin(), wd.end(), str);
                if (it != wd.end() && *it == str)
                    f |= helper(i + 1);
            }
            return record[k] = f;
        };
        return helper(0);
    }
};
