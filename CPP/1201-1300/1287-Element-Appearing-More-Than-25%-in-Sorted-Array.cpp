class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int k = arr.size() / 4;
        for (int i = 0; i < arr.size() - k; ++i)
            if (arr[i] == arr[i + k])
                return arr[i];
        return arr[0];
    }
};
