class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> record({{1, 0}});
        vector<int> arr(hi - lo + 1);
        for (int i = 0; i <= hi - lo; ++i)
            arr[i] = lo + i;

        for (int i = lo; i <= hi; ++i) {
            int k(i);
            vector<int> arr;
            while (!record.count(k)) {
                arr.push_back(k);
                k = k % 2 ? 3 * k + 1 : k / 2;
            }
            reverse(arr.begin(), arr.end());
            for (int i = 0; i < arr.size(); ++i)
                record[arr[i]] = record[k] + i + 1;
        }

        sort(arr.begin(), arr.end(), [&](const int& x, const int& y){return record[x] < record[y] || record[x] == record[y] && x < y;});

        return arr[k-1];
    }
};
