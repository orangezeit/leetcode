class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        while (--n) {
            str += ' ';
            string newStr;
            int c(-1);

            for (int i = 0; i + 1 < str.length(); ++i)
                if (str[i] != str[i + 1]) {
                    newStr += to_string(i - c) + str[i];
                    c = i;
                }

            swap(str, newStr);
        }
        return str;
    }
};
