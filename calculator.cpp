#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>


using namespace std;

class Calculator {
//private:
public:
    int digit(string& num) {

        /*** detect if decimal and remove extra zeros ***/

        int start = 0;
        if (num[start] == '-')
            start++;

        while (num[start] == '0')
            start++;

        for (int i = start; i < num.length(); ++i) {
            if (num[i] == '.') {
                int t = 0;
                int last = num.length() - 1;

                if (num[start] == '.') start--;

                while (num[last] == '0')
                    last--;

                if (num[last] != '.')
                    while(i < last) {
                        num[i] = num[i+1];
                        i++;
                        t++;
                    }

                num = string(num.begin()+start, num.begin()+last);
                cout << "t" << endl;
                return t;
            }
        }

        num = string(num.begin()+start, num.end());
        if (num.empty()) num = "0";
        return 0;
    }

    bool compare(string& num1, string& num2, int& d) {

        int d1(digit(num1)), d2(digit(num2));
        d = max(d1, d2);

        d1 < d2 ? num1 += string(d2-d1, '0') : num2 += string(d1-d2, '0');

        return num1.length() != num2.length() ? num1.length() > num2.length() : num1 > num2;
    }

    bool is_op(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    string abs(string num) {
        if (num[0] == '-')
            num[0] = '0';
        return num;
    }

    string add(string& num1, string& num2, const char& op) {

        int d1(digit(num1)), d2(digit(num2)), d(max(d1, d2));
        d1 < d2 ? num1 += string(d2-d1, '0') : num2 += string(d1-d2, '0');

        if (num1.length() < num2.length())
            num1.swap(num2);

        int n1(num1.length()), n2(num2.length());
        vector<int> sum(n1 + 1, 0);

        for (int i = 0; i < n1; ++i) {
            sum[n1-i] += num1[n1-i-1]-'0';
            if (i < n2)
                sum[n1-i] += num2[n2-i-1]-'0';

            if (sum[n1-i] > 9) {
                sum[n1 - i] -= 10;
                sum[n1 - i - 1]++;
            }
        }

        string str;
        if (op == '-') str += '-';
        for (int i = (!sum[0]); i < n1 + 1; ++i) {
            if (i + d == n1 + 1)
                str += '.';
            str += sum[i] + '0';
        }

        return str;
    }

    string substract(const string& num1, const string& num2, const int& d, const char& op) {

        string str;
        if (op == '-') str += '-';

        if (num2 == "0") {
            str += num1;
            return str;
        }

        int n1(num1.length()), n2(num2.length());

        vector<int> diff(n1, 0);

        for (int i = 0; i < n1; ++i) {
            i < n2 ? diff[n1-i-1] += num1[n1-i-1] - num2[n2-i-1] : diff[n1-i-1] += num1[n1-i-1] - '0';

            if (diff[n1-i-1] < 0) {
                diff[n1-i-1] += 10;
                diff[n1-i-2]--;
            }
        }

        for (int i = 0; i < n1; ++i) {
            if (!diff[i] && i + d < n1 - 1)
                continue;
            if (i + d == n1)
                str += '.';
            str += diff[i] + '0';
        }

        return str;
    }

    char rvs(const char& c) {
        return c == '+' ? '-' : '+';
    }

    string pm(string& n1, string& n2, char& op) {
        //
        if (n2[0] == '-') {
            n2[0] = '0';
            op == '+' ? op = '-' : op = '+';
        }

        int d = 0;

        if (n1[0] == '-') {
            n1[0] = '0';
            if (op == '+')
                return compare(n1, n2, d) ? substract(n1, n2, d, '-') : substract(n2, n1, d, '+');
        } else {
            if (op == '-')
                return compare(n1, n2, d) ? substract(n1, n2, d, '+') : substract(n2, n1, d, '-');
        }

        return add(n1, n2, op);
    }

    string multiply(string num1, string num2) {
        cout << num1 << " " << num2 << endl;
        bool sign1(num1[0] == '-'), sign2(num2[0] == '-');

        int d1(digit(num1)), d2(digit(num2)), d(d1 + d2);
        cout << num1 << " " << num2 << endl;
        cout << d1 << "d" << d2 << endl;
        if (num1 == "0" || num2 == "0")
            return "0";

        if (num1.length() < num2.length())
            num1.swap(num2);

        int n1(num1.length()), n2(num2.length());
        vector<int> product(n1 + n2, 0);
        int p1(0), p2(0), q1(0), q2(0), k(1);
        string str;

        if (sign1^sign2) {
            str += '-';
            cout << "a" << endl;
        }

        while (p1 <= p2) {
            for(int i = 0; i <= p2-p1; ++i)
                product[k] += (num1[p1+i]-'0') * (num2[q2-i]-'0');

            if (q2 < n2 - 1) {
                p2++;
                q2++;
            } else if (p2 < n1 - 1) {
                p1++;
                p2++;
            } else {
                p1++;
                q1++;
            }

            k++;
        }

        for (int i = n1 + n2 -1; i > 0; --i) {
            product[i-1] += product[i] / 10;
            product[i] %= 10;
        }

        for (int i = (!product[0]); i < n1 + n2; ++i) {
            if (i + d == n1 + n2)
                str += '.';
            str += product[i] + '0';
        }
        cout << "str" << str << endl;
        return str;
    }

    string divide(string num1, string num2) {
        string str = "1";
        return str;
    }

    string factorial(string num) {
        string ans = "1";

        while (num != "0") {
            ans = multiply(ans, num);
            num = substract(num, "1", 0, '+');
        }

        return ans;
    }

    string permutation(string n, string r) {
        return divide(factorial(n), factorial(r));
    }

    string combination(string n, string r) {
        return divide(factorial(n), multiply(factorial(r), factorial(substract(n, r, 0, '+'))));
    }

    string exp(string num) {

    }

    string ln(string num) {

    }

    string int_power(string num1, string num2, int d) {
        string bin = "101";
        num1.insert(num1.end()-d, '.');
        string base = num1;
        string res = "1";

        for (int i = 0; i < bin.length(); ++i) {
            if (bin[i] - '0')
                res = multiply(res, base);
            if (i != bin.length() - 1)
                base = multiply(base, base);
        }

        return res;
    }

    string power(string num1, string num2) {
        if (num2[0] == '-') {
            num2[0] = '0';
            return divide("1", power(num1, num2));
        }

        bool ng1(num1[0] == '-');
        int d1(digit(num1)), d2(digit(num2));

        if (d2) {
            if (num1 == "0") {
                return "0";
            } else {
                return ng1 ? "Error" : exp(multiply(ln(num1), num2));
            }
        } else {
            cout << "is integer" << endl;
            if (num1 == "0") {
                return num2 == "0" ? "Error" : "1";
            } else {
                return int_power(num1, num2, d1);
            }
        }
    }

    string log(string a, string b) {
        string str = "1";

        return str;
    }

    string sin(string num) {

    }

    string cos(string num) {

    }

    string tan(string num) {

    }

    string cot(string num) {

    }

    string arcsin(string num) {

    }

    string arccos(string num) {

    }

    string arctan(string num) {

    }

    string arccot(string num) {

    }

    string inner(string eq) {
        eq += "+0";

        deque<string> nums;
        deque<char> ops;
        queue<char> ops2;
        stack<string> pows;

        nums.push_back("");
        nums.back() += eq[0];

        for (int i = 1; i < eq.length(); ++i) {
            if (is_op(eq[i]))  {
                if (!pows.empty()) {
                    pows.push(nums.back());
                    nums.pop_back();
                    while (pows.size() > 1) {
                        string temp = pows.top();
                        pows.pop();
                        pows.top() = power(pows.top(), temp);
                    }
                    nums.push_back(pows.top());
                    pows.pop();
                }
                is_op(eq[i-1]) ? nums.push_back("-") : ops.push_back(eq[i]);
            } else if (eq[i] == '^') {
                pows.push(nums.back());
                nums.pop_back();
            } else {
                if (nums.empty())
                    nums.push_back("");
                else if (is_op(eq[i-1]) && nums.back() != "-")
                    nums.push_back("");
                nums.back() += eq[i];
            }
        }

        while (!ops.empty()) {
            if (ops.front() == '*' || ops.front() == '/') {
                string temp1 = nums.front();
                nums.pop_front();
                string temp2 = nums.front();
                nums.pop_front();

                ops.front() == '*' ? nums.push_front(multiply(temp1, temp2)) : nums.push_front(divide(temp1, temp2));
                ops.pop_front();
            } else {
                nums.push_back(nums.front());
                nums.pop_front();
                ops2.push(ops.front());
                ops.pop_front();
            }
        }

        nums.push_back(nums.front());
        nums.pop_front();

        while (!ops2.empty()) {
            string temp1 = nums.front();
            nums.pop_front();
            string temp2 = nums.front();
            nums.pop_front();

            nums.push_front(pm(temp1, temp2, ops2.front()));
            ops2.pop();
        }
        //cout << "ans: " << nums.back() << endl;
        return nums.back();
    }

    string eval(string eps) {
        stack<string> bkts;

        if (eps[0] != '(')
            bkts.push("");

        for (int i = 0; i < eps.length(); ++i) {
            if (eps[i] == '(') {
                bkts.push("");
            } else if (eps[i] == ')') {
                string temp = inner(bkts.top());
                bkts.pop();
                bkts.top() += temp;
            } else {
                bkts.top() += eps[i];
            }
        }

        return inner(bkts.top());
    }
};

int main() {
    Calculator c;
    string num1 = "-10000000", num2 = "-0.0";
    char op = '-';
    //string test = c.pm(num1, num2, op);
    string num3 = "-0000.0002300400";
    string t = c.power("0.23", "5.00");
    cout << t << endl;
    return 0;
}
