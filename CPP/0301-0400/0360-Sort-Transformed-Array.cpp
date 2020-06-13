class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ta(nums.size());
        int k;

        if (a == 0) {
            b < 0 ? k = nums.size() - 1 : k = 0;

            for (int i = 0; i < nums.size(); ++i) {
                ta[k] = nums[i] * b + c;
                b < 0 ? k-- : k++;
            }

            return ta;
        }



        double e = - 0.5 * b / a;

        int i(0), j(nums.size() - 1);
        a > 0 ? k = nums.size() - 1 : k = 0;

        while (i <= j) {
            if (abs(nums[i] - e) > abs(nums[j] - e)) {
                ta[k] = a * nums[i] * nums[i] + b * nums[i++] + c;
            } else {
                ta[k] = a * nums[j] * nums[j] + b * nums[j--] + c;
            }
            a > 0 ? k-- : k++;
        }

        return ta;
    }
};
