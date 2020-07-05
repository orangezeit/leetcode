class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a)
            if (to_string(a).find('0') == string::npos && to_string(n - a).find('0') == string::npos)
                return {a, n - a};
        return {};
    }
};
