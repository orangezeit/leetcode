class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        bool nf = true;

        for (int i = str.length() - 2; i >= 0; --i) {
            if (str[i] < str[i+1]) {
                for (int j = str.length() - 1; j >= i; --j) {
                    if (str[j] > str[i]) {
                        swap(str[i], str[j]);
                        reverse(str.begin() + i + 1, str.end());
                        break;
                    }
                }
                nf = false;
                break;
            }
        }

        return nf ? -1 : str.length() == 10 && str > "2147483647" ? -1 : stoi(str);
    }
};
