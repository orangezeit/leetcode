class Solution {
public:
    bool isStrobogrammatic(string num) {
        for (int i = 0; i <= num.length() / 2; ++i) {
            if (num[i] == '0' || num[i] == '1' || num[i] == '8') {
                if (num[i] != num[num.length() - i - 1])
                    return false;
            } else if (num[i] == '6') {
                if (num[num.length() - i - 1] != '9')
                    return false;
            } else if (num[i] == '9') {
                if (num[num.length() - i - 1] != '6')
                    return false;
            } else {
                return false;
            }
        }
        return true;
    }
};
