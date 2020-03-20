class Solution {
public:
    int romanToInt(string s) {
        vector<int> nums(s.length() + 1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'I') {
                nums[i] = 1;
            } else if (s[i] == 'V') {
                nums[i] = 5;
            } else if (s[i] == 'X') {
                nums[i] = 10;
            } else if (s[i] == 'L') {
                nums[i] = 50;
            } else if (s[i] == 'C') {
                nums[i] = 100;
            } else if (s[i] == 'D') {
                nums[i] = 500;
            } else {
                nums[i] = 1000;
            }
        }

        int sum = 0;

        for (int i = nums.size()-1; i >= 1; --i) {
            nums[i-1] >= nums[i] ? sum += nums[i-1] : sum -= nums[i-1];
        }

        return sum;
    }
};
