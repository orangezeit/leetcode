class Solution {
public:
    bool isArmstrong(int N) {
        string str = to_string(N);
        int res = 0;

        for (int i = 0; i < str.length(); ++i)
            res += pow(str[i] - '0', str.length());

        return res == N;
    }
};
