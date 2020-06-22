class Solution {
public:
    string smallestGoodBase(string n) {
        long long N = stoll(n);

        for (int m = log(N+1) / log(2); m >= 2; --m) {
            long long left = 2;
            long long right = pow(N, 1.0 / (m - 1));
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                long long sum = 1;
                for (int i = 1; i < m; ++i)
                    sum = sum * mid + 1;
                if (sum == N) return to_string(mid);
                sum < N ? left = mid + 1 : right = mid - 1;
            }
        }

        return to_string(N-1);
    }
};
