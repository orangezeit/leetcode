class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> rec({{0, 0}, {1, 1}});
        function<int(int)> check = [&](int x) {
            return rec.count(x) ? rec[x] : rec[x] = min(check(x / 2) + x % 2, check(x / 3) + x % 3) + 1;
        };
        return check(n);
    }
};
