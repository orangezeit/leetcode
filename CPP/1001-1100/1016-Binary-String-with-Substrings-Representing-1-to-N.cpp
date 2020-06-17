class Solution {
public:
    string binary(int i) {
        string str;

        while (i) {
            str += '0' + i % 2;
            i /= 2;
        }
        reverse(str.begin(), str.end());
        return str;
    }

    bool queryString(string S, int N) {
        if (N >= 2048)
            return false;

        for (int i = 1; i <= N; ++i)
            if (S.find(binary(i)) == string::npos)
                return false;

        return true;
    }
};
