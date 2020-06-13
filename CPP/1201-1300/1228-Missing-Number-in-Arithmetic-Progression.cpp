class Solution {
public:
    int missingNumber(vector<int>& arr) {
        //unordered_map<int, pair<int, int>> rec;
        int d(0), prev(0);
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (i && d != arr[i + 1] - arr[i])
                return abs(arr[i + 1] - arr[i]) > abs(d) ? (arr[i + 1] + arr[i]) / 2 : prev + d / 2;
            d = arr[i + 1] - arr[i];
            prev = arr[i];
        }

        return arr[0];
    }
};
