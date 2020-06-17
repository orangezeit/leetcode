class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() < arr2.size())
            swap(arr1, arr2);
        int len1(arr1.size()), len2(arr2.size());
        vector<int> res(len1 + 2, 0);

        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());

        for (int i = 0; i < len1; ++i) {
            res[i] += arr1[i];
            if (i < len2) res[i] += arr2[i];
            if (res[i] > 1) {
                res[i+2]++;
                if (res[i] % 4) res[i+1]++;
                res[i] %= 2;
            }
        }

        if (res[len1] == 2) {
            res.pop_back();
            res.pop_back();
        }

        while (res.back() == 0 && res.size() > 1) {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
