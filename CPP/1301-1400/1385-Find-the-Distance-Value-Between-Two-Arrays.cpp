class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans(0);
        for (int i: arr1) {
            bool test(true);
            for (int j: arr2) {
                if (abs(i - j) <= d) {
                    test = false;
                    break;
                }
            }
            if (test) ans++;
        }
        return ans;
    }
};
