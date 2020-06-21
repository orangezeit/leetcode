class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        // Method 1: Greedy
        int ans(0);
        for (int i = 0; i < row.size(); i += 2) {
            // check pairs
            // if first is less than second, we swap -> simplify analysis
            if (row[i] > row[i+1]) swap(row[i], row[i+1]);
            // if diff is 1 and follows (even, odd), e.g (0, 1), then valid
            // notice that (odd, even), e.g (1, 2), is invalid
            if (row[i+1] - row[i] == 1 && row[i+1] % 2) continue;
            // for invalid, we have to swap one element, fix first
            // if first odd, then second must be odd - 1
            // if first even, then second must be even + 1
            // iterate from i + 2 to end to find the other, and swap
            int target = row[i] % 2 ? row[i] - 1 : row[i] + 1;
            for (int j = i + 2; j < row.size(); ++j)
                if (row[j] == target) {
                    swap(row[j], row[i+1]);
                    ans++;
                    break;
                }
        }

        return ans;
    }
};
