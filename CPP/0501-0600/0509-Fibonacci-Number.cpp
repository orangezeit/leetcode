class Solution {
public:
    int fib(int n) {
        array<int, 2> ans({0, 1});

        for (int i = 0; i < n; ++i)
            i % 2 ? ans[0] += ans[1] : ans[1] += ans[0];

        return ans[n % 2];
    }
};
