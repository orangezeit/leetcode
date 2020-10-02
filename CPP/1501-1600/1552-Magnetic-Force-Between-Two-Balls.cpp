class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left(1), right(position.back() - position.front() + 1), n(position.size());
        auto check = [&](int d) {
            int prev(position[0]), cnt(1);
            for (int i = 1; i < n; ++i)
                if (position[i] - prev >= d) {
                    if (++cnt >= m) return true;
                    prev = position[i];
                }
            return false;
        };
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
