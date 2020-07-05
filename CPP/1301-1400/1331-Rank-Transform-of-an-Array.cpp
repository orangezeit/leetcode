class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n(arr.size());
        vector<int> ranks(n);
        vector<pair<int, int>> arr2(n);
        for (int i = 0; i < n; ++i) {
            arr2[i].first = arr[i];
            arr2[i].second = i;
        }
        sort(arr2.begin(), arr2.end());
        ranks[arr2[0].second] = 1;
        for (int i = 1; i < n; ++i) {
            ranks[arr2[i].second] = ranks[arr2[i-1].second] + (arr2[i-1].first == arr2[i].first);
        }
        return ranks;
    }
};
