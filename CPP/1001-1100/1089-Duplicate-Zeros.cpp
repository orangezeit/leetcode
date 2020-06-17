class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int k(0);

        for (int i = 0; i < arr.size(); ++i)
            if (arr[i] == 0) k++;

        for (int i = arr.size() - 1; i >= 0; --i) {
            if (i+k < arr.size())
                arr[i+k] = arr[i];

            if (arr[i] == 0) {
                k--;
                if (i+k < arr.size())
                    arr[i+k] = 0;
            }
        }
    }
};
