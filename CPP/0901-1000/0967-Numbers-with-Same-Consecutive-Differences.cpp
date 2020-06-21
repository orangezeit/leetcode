class Solution {
public:
    void bt(int& curr, unordered_set<int>& nums, const int& K, int& N) {
        if (N == 1) {
            nums.insert(curr);
            return;
        }

        int digit = curr % 10;
        if (digit + K <= 9) {
            curr *= 10;
            curr += digit + K;
            N--;
            bt(curr, nums, K, N);
            N++;
            curr /= 10;
        }
        if (digit - K >= 0) {
            curr *= 10;
            curr += digit - K;
            N--;
            bt(curr, nums, K, N);
            N++;
            curr /= 10;
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        unordered_set<int> nums;
        for (int i = 1; i <= 9; ++i) {
            bt(i, nums, K, N);
        }
        if (N == 1) nums.insert(0);
        return vector<int>(nums.begin(), nums.end());
    }
};
