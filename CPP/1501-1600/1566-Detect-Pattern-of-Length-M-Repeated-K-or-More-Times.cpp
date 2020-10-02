class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n(arr.size()), start(0), indices[k];
        while (start + m * k <= n) {
            indices[0] = start++;
            bool repeated(true);
            for (int r = 0; r < m && repeated; ++r, ++indices[0])
                for (int i = 1; i < k && repeated; ++i)
                    repeated = arr[indices[i] = indices[i - 1] + m] == arr[indices[0]];
            if (repeated) return true;
        };

        return false;
    }
};
