class Solution {
public:
    long count(const string& S, vector<vector<long>>& m, int start, int end) {
        if (start > end) return 0;
        if (start == end) return 1;
        if (m[start][end]) return m[start][end];

        long ans(0);

        if (S[start] == S[end]) {
            int left(start + 1), right(end - 1);
            while (left <= right && S[left] != S[start]) left++;
            while (left <= right && S[right] != S[start]) right--;
            if (left > right)
                ans = 2 * count(S, m, start + 1, end - 1) + 2;
            else if (left == right)
                ans = 2 * count(S, m, start + 1, end - 1) + 1;
            else
                ans = 2 * count(S, m, start + 1, end - 1) - count(S, m, left + 1, right - 1);
        } else {
            ans = count(S, m, start + 1, end) + count(S, m, start, end - 1) - count(S, m, start + 1, end - 1);
        }

        return m[start][end] = (ans + 1000000007) % 1000000007;
    }
    int countPalindromicSubsequences(string S) {
        vector<vector<long>> m(S.length(), vector<long>(S.length()));
        return count(S, m, 0, S.length() - 1);
    }
};
