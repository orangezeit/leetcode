class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string str;
        while (N) {
            int r = N % (-2);
            N /= (-2);
            if (r < 0) {
                r += 2;
                N += 1;
            }
            str.push_back('0' + r);
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
