class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] += arr[i-1];
            if (arr[i] > 5000) return i;
        }
        return arr.size();
    }
};
