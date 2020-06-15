class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> presums({{0, -1}});
        int n = arr.size();
        vector<int> info(n);
        int ans(n + 1);

        for (int i = 1; i < n; ++i)
            arr[i] += arr[i - 1];

        for (int i = 0; i < n; ++i) {
            info[i] = i ? info[i - 1] : 1e9;
            if (presums.count(arr[i] - target)) {
                int idx = presums[arr[i] - target];
                info[i] = min(info[i], i - idx);
                if (idx >= 0) ans = min(ans, info[idx] + i - idx);
            }
            presums[arr[i]] = i;
        }

        return ans > n ? -1 : ans;
    }
};
