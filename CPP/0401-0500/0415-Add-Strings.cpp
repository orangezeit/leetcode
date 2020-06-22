class Solution {
public:
    string reverse(string str) {
        char temp;

        for (int i = 0; i < str.length() / 2; ++i) {
            temp = str.at(i);
            str.at(i) = str.at(str.length() - i - 1);
            str.at(str.length() - i - 1) = temp;
        }

        return str;
    }

    string addStrings(string num1, string num2) {
        int shortSize = min(num1.size(), num2.size());

        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        int n3;
        int t = 0;
        int digit;
        string str, front;
        bool one = false;

        while (t < shortSize) {
            digit = num1.at(n1-t) - '0' + num2.at(n2-t) - '0';

            if (one) {
                digit++;
            }

            if (digit <= 9) {
                str.push_back(digit + '0');
                one = false;
            } else {
                str.push_back(digit - 10 + '0');
                one = true;
            }

            t++;
        }

        if (num1.size() != num2.size()) {
            t = 0;

            if (num1.size() > num2.size()) {
                front = num1.substr(0, num1.size() - num2.size());
            } else {
                front = num2.substr(0, num2.size() - num1.size());
            }

            n3 = front.size();

            while (t < n3) {
                digit = front.at(n3-t-1) - '0';
                if (one) {
                    digit++;
                }

                if (digit <= 9) {
                    str.push_back(digit + '0');
                    one = false;
                } else {
                    str.push_back(digit - 10 + '0');
                    one = true;
                }
                t++;
            }

        }

        if (one) {
            return reverse(str + "1");
        } else {
            return reverse(str);
        }

    }
};
