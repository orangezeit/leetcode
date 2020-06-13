class Solution {
public:
    string encode(int num) {
        num++;
        string ans;

        while (num > 1) {
            ans += '0' + num % 2;
            num /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
