class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // we label number greater than 8 as 1, otherwise -1
        // try to find the longest interval whose sum is positive

        unordered_map<int, int> record;
        int sum(0), ans(0);

        for (int i = 0; i < hours.size(); ++i) {
            hours[i] > 8 ? sum++ : sum--;
            if (!record.count(sum)) {
                record[sum] = i;
            }
            if (sum > 0) {
                ans = max(ans, i + 1);
            } else {
                if (record.count(sum - 1)) {
                    ans = max(ans, i - record[sum - 1]);
                }
            }
        }

        return ans;
    }
};
