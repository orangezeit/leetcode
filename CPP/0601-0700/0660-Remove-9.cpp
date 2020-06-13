class Solution {
public:
    int newInteger(int n) {
        string str;
        while (n) {
            str += '0' + n % 9;
            n /= 9;
        }
        reverse(str.begin(), str.end());
        return stoi(str);
    }
};
