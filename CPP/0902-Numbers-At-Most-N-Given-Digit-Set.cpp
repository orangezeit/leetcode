class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {

        string str = to_string(N);
        int len = str.length();

        int sum = 0;
        int power = 1;

        for (int i = 0; i < len - 1; ++i) {
            power *= D.size();
            sum += power;
        }

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < D.size(); ++j) {
                if (D[j][0] < str[i]) {
                    sum += power;
                } else if (D[j][0] == str[i]) {
                    if (i == len-1) sum++;
                    break;
                } else {
                    return sum;
                }
            }

            if (D.back()[0] < str[i]) break;
            power /= D.size();
        }

        return sum;
    }
};
