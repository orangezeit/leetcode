class Solution {
public:
    int magicalString(int n) {
        string str = "122";
        int i = 2;
        int cnt(0);
        while (str.length() < n) {
            char c = '3' - str.back() + '0';
            str += c;
            if (str[i++] == '2')
                str += c;
        }
        for (int i = 0; i < n; ++i)
            cnt += str[i] == '1';
        return cnt;
    }
};
