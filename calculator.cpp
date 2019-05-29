#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm> // reverse


using namespace std;

class Calculator {
private:
    string pi, half_pi, double_pi;
    string e;
    int p;

    void calculate_pi() {
        pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
        half_pi = divide(pi, "2");
        double_pi = multiply(pi, "2");
    }

public:

    Calculator(int percision) {
        p = 2 * percision;
    }

    string base(string num, int n, int m, bool reversed=false) {

        if (n < 2 || n > 36 || m < 2 || m > 36)
            return "Error";
        if (n == m)
            return num;

        bool sign(num[0] == '-');

        if (sign) num[0] = '0';

        unsigned long long int temp = 0;
        string ans;

        for (int i = 0; i < num.length(); ++i)
            num[i] >= '0' && num[i] <= '9' ? temp = (temp * n + num[i] - '0') : temp = (temp * n + num[i] - 'a' + 10);

        while (temp) {
            int d = temp % m;
            d < 10 ? ans += d + '0' : ans += d + 'a' - 10;
            temp /= m;
        }

        if (sign) ans += '-';

        if (!reversed)
            reverse(ans.begin(), ans.end());
        return ans;
    }

    int digit(string& num, bool test=false) {

        /**
            remove extra zeros from both sides
            return location of decimal points
        **/

        int start(0);
        if (num[start] == '-') start++;
        while (num[start] == '0') start++;

        for (int i = start; i < num.length(); ++i) {
            if (num[i] == '.') {
                int d(0), last(num.length() - 1);

                if (num[start] == '.') start--;
                while (num[last] == '0') last--;

                if (num[last] != '.')
                    while(i < last) {
                        num[i] = num[i+1];
                        i++;
                        d++;
                    }
                if (test) while(num[start] == '0') start++;
                num = string(num.begin()+start, num.begin()+last);
                return d;
            }
        }

        num = string(num.begin()+start, num.end());
        if (num.empty())
            num = "0";
        return 0;
    }

    bool int_compare(string num1, string num2) {
        /** return true if num1 > num2 else false **/
        return num1.length() != num2.length() ? num1.length() > num2.length() : num1 > num2;
    }

    bool compare(string& num1, string& num2, int& d) {

        int d1(digit(num1)), d2(digit(num2));
        d = max(d1, d2);

        d1 < d2 ? num1 += string(d2-d1, '0') : num2 += string(d1-d2, '0');

        return int_compare(num1, num2);
    }

    bool is_op(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    string abs(string num) {
        if (num[0] == '-')
            num[0] = '0';
        return num;
    }

    string add(string num1, string num2, const char op='+') {
        /**
            num1 / num2: non-negative, could be decimal
            op: the sign of ans
        **/

        string ans;
        if (op == '-') ans += '-';

        int d1(digit(num1)), d2(digit(num2)), d(max(d1, d2));
        d1 < d2 ? num1 += string(d2 - d1, '0') : num2 += string(d1 - d2, '0');

        if (num1.length() < num2.length())
            swap(num1, num2);

        int n1(num1.length()), n2(num2.length());
        vector<int> sum(n1 + 1, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n1; ++i) {
            sum[i] += num1[i] - '0';
            if (i < n2)
                sum[i] += num2[i] - '0';
            if (sum[i] > 9) {
                sum[i] -= 10;
                sum[i+1]++;
            }
        }

        reverse(sum.begin(), sum.end());

        for (int i = (!sum[0]); i <= n1; ++i) {
            ans += sum[i] + '0';
            if (d && i + d == n1)
                ans += '.';
        }

        return ans;
    }

    string subtract(string num1, string num2, const int d=0, const char op='+') {
        /**
            num1 / num2: non-negative, integer (modified during comparison)
            d: location of decimal point
            op: the sign that applies to ans
        **/
        string ans;
        if (op == '-') ans += '-';

        if (num2 == "0")
            return ans + num1;

        int n1(num1.length()), n2(num2.length());
        vector<int> diff(n1, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n1; ++i) {
            i < n2 ? diff[i] += num1[i] - num2[i] : diff[i] += num1[i] - '0';

            if (diff[i] < 0) {
                diff[i] += 10;
                diff[i+1]--;
            }
        }

        reverse(diff.begin(), diff.end());

        bool flag = true;
        for (int i = 0; i < n1; ++i) {
            if (!diff[i] && i + d < n1 - 1 && flag)
                continue;
            flag = false;
            if (i + d == n1)
                ans += '.';
            ans += diff[i] + '0';
        }

        return ans;
    }

    string pm(string n1, string n2, char op) {

        /** num1 adds or subtracts num2 **/

        if (n2[0] == '-') {
            n2[0] = '0';
            op == '+' ? op = '-' : op = '+';
        }

        int d = 0;

        if (n1[0] == '-') {
            n1[0] = '0';
            if (op == '+')
                return compare(n1, n2, d) ? subtract(n1, n2, d, '-') : subtract(n2, n1, d);
        } else {
            if (op == '-')
                return compare(n1, n2, d) ? subtract(n1, n2, d) : subtract(n2, n1, d, '-');
        }

        return add(n1, n2, op);
    }

    string multiply(string num1, string num2) {

        /** num1 multipies num2 **/

        string ans;

        if ((num1[0] == '-')^(num2[0] == '-'))
            ans += '-';

        int d1(digit(num1)), d2(digit(num2)), d(d1 + d2);

        if (num1 == "0" || num2 == "0")
            return "0";

        int n1(num1.length()), n2(num2.length());
        vector<int> product(n1 + n2, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < n2; ++j)
                product[i+j] += (num1[i] - '0') * (num2[j] - '0');

        for (int i = 0; i < n1 + n2 - 1; ++i) {
            product[i+1] += product[i] / 10;
            product[i] %= 10;
        }

        reverse(product.begin(), product.end());

        for (int i = (!product[0]); i < n1 + n2; ++i) {
            if (i + d == n1 + n2)
                ans += '.';
            ans += product[i] + '0';
        }

        return ans;
    }

    string divide(string num1, string num2, const int r=-1) {

        string ans;

        if ((num1[0] == '-')^(num2[0] == '-'))
            ans += '-';

        int d1(digit(num1, true)), d2(digit(num2));
        d1 < d2 ? num1 += string(d2-d1, '0') : num2 += string(d1-d2, '0');

        num1 += string(p, '0');
        string pre = "1";
        string base = "1";
        string res = "0";
        string inter = "0";
        string ext = num1;

        while (int_compare(ext, num2)) {
            while (int_compare(num1, inter)) {
                res = add(res, base);
                pre = base;
                base = multiply(base, "2");
                inter = multiply(num2, res);
            }
            res = subtract(res, pre);
            inter = subtract(inter, multiply(pre, num2));
            pre = "1";
            base = "1";
            ext = subtract(num1, inter);
        }

        if (ext == num2) res = add(res, "1");

        if (p >= res.length()) {
            res = "0." + string(p - res.length(), '0') + res;
        } else {
            res.insert(res.end()-p, '.');
        }

        ans += res;
        return ans;
    }

    string factorial(string num) {
        if (num[0] == '-')
            return "Error";
        if (digit(num))
            return "Error";

        string ans = "1";

        while (num != "0") {
            ans = multiply(ans, num);
            num = subtract(num, "1");
        }

        return ans;
    }

    string permutation(string n, string r) {

        if (digit(n) || digit(r))
            return "Error";

        string base = r;
        string ans = "1";

        while (base != n) {
            base = add(base, "1");
            ans = multiply(ans, base);
        }

        return ans;
    }

    string combination(string n, string r) {
        string s = subtract(n, r);
        return int_compare(s, r) ? combination(n, s) : divide(permutation(n, r), factorial(s));
    }

    string int_power(string num1, string num2, int d) {
        string bin = base(num2, 10, 2, true);

        if (d >= num1.length()) {
            num1 = "0." + string(d - num1.length(), '0') + num1;
        } else {
            num1.insert(num1.end()-d, '.');
        }

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

    string e_power(string num) {
        string term, x(num), i("1"), ans("1");

        while (term != "0") {
            term = divide(x, factorial(i));
            ans = add(ans, term);
            x = multiply(num, x);
            i = add(i, "1");
            digit(term);
        }

        return ans;
    }

    string exp(string num) {
        if (e.empty())
            e = e_power("1");

        int d(digit(num));
        string ans = int_power(e, string(num.begin(), num.end()-d), 0);

        if (d)
            ans = multiply(ans, e_power("0." + string(num.end()-d, num.end())));
        return ans;
    }

    string ln02(string num) {
        num = pm(num, "1", '-');

        string term, x(num), i("1"), ans("0");
        bool flag(true);

        while (term != "0") {
            term = divide(x, i);
            cout << term << endl;
            flag ? ans = pm(ans, term, '+') : ans = pm(ans, term, '-');
            flag = !flag;
            x = multiply(num, x);
            i = add(i, "1");
            digit(term);
        }

        return ans;
    }

    string ln(string num) {
        if (num[0] = '-') return "Error";
        int k = 0;
        //num = divide(num, "2");
        /*
        while (num > 2) {
            num /= 2;
            k++;
            if (num == "0") return "Error";
        }*/

        return num; // k * ln02("2") + ln02(num);
    }

    string power(string num1, string num2) {
        cout << num1 << " " << num2 << endl;
        if (num2[0] == '-') {
            num2[0] = '0';
            return divide("1", power(num1, num2));
        }

        bool ng(num1[0] == '-');
        int d1(digit(num1)), d2(digit(num2));

        if (d2) {
            return num1 == "0" ? "0" : ng ? "Error" : exp(multiply(ln(num1), num2));
        } else {
            return num1 == "0" ? num2 == "0" ? "Error" : "1" : int_power(num1, num2, d1);
        }
    }

    string log(string a, string b) {
        return divide(ln(b), ln(a));
    }

    string sin(string num) {
        if (pi.empty())
            calculate_pi();

        if (num[0] == '-') {
            num[0] = '0';
            return "-" + sin(num);
        }
        /*
        while (num > 2 * pi) {
            num = pm(num, double_pi, '-');
        }

        if (num > pi) {
            return "-" + sin(pm(num, pi, '-'));
        } else if (num > pi/2) {
            return sin(pm(pi, num, '-'));
        }*/

        // between 0 and pi / 2

        string term, x(num), i("1"), ans("0");
        num = multiply(num, num);
        bool flag(true);

        while (term != "0") {
            term = divide(x, factorial(i));
            flag ? ans = pm(ans, term, '+') : ans = pm(ans, term, '-');
            flag = !flag;
            x = multiply(num, x);
            i = add(i, "2");
            digit(term);
        }

        return ans;
    }

    string cos(string num) {
        if (pi.empty())
            calculate_pi();
        //return sin(pm(half_pi, num, '-'));

        if (num[0] == '-') {
            num[0] = '0';
            return cos(num);
        }
        /*
        while (num > 2 * pi) {
            num = pm(num, double_pi, '-');
        }

        if (num > pi) {
            return cos(pm(double_pi, num, '-'));
        } else if (num > pi/2) {
            return "-" + cos(pm(pi, num, '-'));
        }*/

        num = multiply(num, num);
        string term, x(num), i("2"), ans("1");
        bool flag(false);

        while (term != "0") {
            term = divide(x, factorial(i));
            flag ? ans = pm(ans, term, '+') : ans = pm(ans, term, '-');
            flag = !flag;
            x = multiply(num, x);
            i = add(i, "2");
            digit(term);
        }

        return ans;
    }

    string tan(string num) {
        return divide(sin(num), cos(num));
    }

    string asin(string num) {
        string term, x(num), i("0"), ans("0");
        num = multiply(num, num);

        while (term != "0") {
            string k = multiply(i, "2");
            string t1 = multiply(combination(k, i), x);
            string t2 = multiply(int_power("4", i, 0), add(k, "1"));
            term = divide(t1, t2);
            ans = add(ans, term);
            x = multiply(num, x);
            i = add(i, "1");
            digit(term);
        }

        return ans;
    }

    string acos(string num) {
        if (pi.empty()) calculate_pi();
        return pm(half_pi, asin(num), '-');
    }

    string atan(string num) {
        string term, x(num), i("1"), ans("0");
        num = multiply(num, num);
        bool flag(true);

        while (term != "0") {
            term = divide(x, i);
            flag ? ans = pm(ans, term, '+') : ans = pm(ans, term, '-');
            flag = !flag;
            x = multiply(num, x);
            i = add(i, "2");
            digit(term);
        }

        return ans;
    }

    string inner(string eq) {

        // Error Handles
        eq += "+0";

        deque<string> nums;
        deque<char> ops;
        queue<char> ops2;
        stack<string> pows;

        nums.push_back("");
        nums.back() += eq[0];

        for (int i = 1; i < eq.length(); ++i) {
            if ((eq[i] >= '0' && eq[i] <= '9') || eq[i] == '.')  {
                if (nums.empty())
                    nums.push_back("");
                else if (is_op(eq[i-1]) && nums.back() != "-")
                    nums.push_back("");
                nums.back() += eq[i];

            } else if (eq[i] == '^') {
                pows.push(nums.back());
                nums.pop_back();
            } else {
                if (pows.size() > 1) {
                    pows.push(nums.back());
                    nums.pop_back();
                    while (pows.size() > 1) {
                        string temp = pows.top();
                        pows.pop();
                        pows.top() = power(pows.top(), temp);
                    }
                    cout << "p" << pows.top();
                    nums.push_back(pows.top());
                    pows.pop();
                }
                is_op(eq[i-1]) ? nums.push_back("-") : ops.push_back(eq[i]);
            }
        }

        while (!ops.empty()) {
            if (ops.front() == '*' || ops.front() == '/') {
                string temp1 = nums.front();
                nums.pop_front();
                string temp2 = nums.front();
                nums.pop_front();

                ops.front() == '*' ? nums.push_front(multiply(temp1, temp2)) : nums.push_front(divide(temp1, temp2, 1));
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
        cout << "ans: " << nums.back() << endl;
        return nums.back();
    }

    string eval(string eps) {
        stack<string> bkts;

        bkts.push("");

        for (int i = 0; i < eps.length(); ++i) {
            if (eps[i] == '(') {
                bkts.push("");
            } else if (eps[i] == ')') {
                if (bkts.size() < 2) return "Error: Extra right brackets";
                string temp = inner(bkts.top());
                if (temp == "Error") return "Error";
                bkts.pop();
                bkts.top() += temp;
            } else {
                bkts.top() += eps[i];
            }
        }

        if (bkts.size() > 1)
            return "Error: Extra left brackets";
        return inner(bkts.top());
    }
};

int main() {
    Calculator c(2);
    string str;

    string num1 = "1.23", num2 = "5.00";
    char op = '+';
    string n = "0.00023";
    string test = c.eval("2*2+2^-2*8"); // 54s
    //string test = c.int_power(c.e, "2", 0);
    //string test2 = c.exp("45.67");
    //string num3 = "-0000.0002300400";
    //string t = c.add("0.23", "5.00", op);
    cout << test << endl;
    //cout << test2 << endl;
    return 0;
}
