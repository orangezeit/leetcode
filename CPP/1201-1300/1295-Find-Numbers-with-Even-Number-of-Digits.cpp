class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans(0);
        for (int& i: nums) {
            int c(0);
            while (i) {
                i /= 10;
                c++;
            }
            if (c % 2 == 0) ans++;
        }
        return ans;
    }
};
