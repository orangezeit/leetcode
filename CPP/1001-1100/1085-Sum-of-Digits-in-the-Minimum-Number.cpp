class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int r(0);
        int m(INT_MAX);

        for (int i = 0; i < A.size(); ++i)
            m=min(m, A[i]);

        string str = to_string(m);

        for (int i = 0; i < str.length(); ++i)
            r += (str[i] - '0');

        return !(r % 2);
    }
};
