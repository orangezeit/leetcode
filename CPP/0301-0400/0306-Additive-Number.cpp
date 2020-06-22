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

    bool verify(string str) {
        return str[0] != '0' || str == "0";
    }

    void continueAdd(string n1, string n2, string num, bool& canAdd) {
        //cout << n1 << " " << n2 << " " << num << endl;
        if (num.empty()) {
            //cout << "w" << endl;
            canAdd = true;
            return;
        } else {

            string sum;

            if (num.length() >= max(n1.length(), n2.length())) {
                sum = num.substr(0, max(n1.length(), n2.length()));

                if (addStrings(n1, n2) == sum && verify(sum)) {

                    continueAdd(n2, sum, num.substr(sum.length(), num.length() - sum.length()), canAdd);
                } else if (num.length() >= max(n1.length(), n2.length()) + 1) {
                    sum = num.substr(0, max(n1.length(), n2.length()) + 1);
                    if (addStrings(n1, n2) == sum && verify(sum)) {
                        continueAdd(n2, sum, num.substr(sum.length(), num.length() - sum.length()), canAdd);
                    }
                }
            }
        }
    }

    void addHelper(string num, bool& canAdd) {
        //cout << num << endl;
        string n1, n2, n3;

        for (int i = 2; i < num.length(); ++i) {

            if (num.length()-i >= (i+1) / 2) {

                for (int j = 1; j < i; ++j) {

                    n1 = num.substr(0,j);
                    n2 = num.substr(j, i-j);
                    n3 = num.substr(i, max(j, i-j));

                    if (addStrings(n1, n2) == n3 && verify(n1) && verify(n2) && verify(n3)) {

                        continueAdd(n2, n3, num.substr(i+max(j,i-j), num.length()-i-max(j,i-j)), canAdd);

                    } else if (num.length()-i >= (i+1) / 2 + 1) {
                        n3 = num.substr(i, max(j, i-j)+1);

                        if (addStrings(n1, n2) == n3 && verify(n1) && verify(n2) && verify(n3)) {

                            continueAdd(n2, n3, num.substr(i+max(j,i-j)+1, num.length()-i-max(j,i-j)-1), canAdd);

                        }
                    }

                    if (canAdd) {
                        return;
                    }

                }

            }

        }

    }

    bool isAdditiveNumber(string num) {
        bool canAdd = false;
        addHelper(num, canAdd);
        return canAdd;
    }
};
