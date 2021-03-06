#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm> // reverse


using namespace std;

class Calculator {
private:
    string pi, half_pi, double_pi, ln2;
    string e;
    int p;

public:

    Calculator(int percision) {
        p = 2 * percision;
    }

    string base(string num, int n, int m, bool reversed=false) {

        if (n < 2 || n > 36 || m < 2 || m > 36)
            return "Error: bases must be between 2 and 36 (inclusive)";
        if (n == m) return num;

        unsigned long long int temp(0);
        string ans;

        for (int i = (num[0] == '-'); i < num.length(); ++i) {
            temp *= n;
            int d;
            num[i] >= '0' && num[i] <= '9' ? d = num[i] - '0' : d = num[i] - 'a' + 10;
            if (d >= n || d < 0) return "Error: invalid digit";
            temp += d;
        }

        while (temp) {
            int d(temp % m);
            d < 10 ? ans += d + '0' : ans += d + 'a' - 10;
            temp /= m;
        }

        if (num[0] == '-') ans += '-';
        if (!reversed) reverse(ans.begin(), ans.end());
        return ans;
    }

    int digit(string& num, bool removed=false) {

        /**
            remove extra zeros from both sides
            return location of decimal points
        **/

        if (num[0] == '.') num.insert(num.begin(), '0');
        int d(0), start(0), last(num.length());
        if (num[start] == '-') start++;
        while (num[start] == '0') start++;

        for (int i = start; i < num.length(); ++i) {
            if (num[i] == '.') {
                last--;
                if (num[start] == '.') start--;
                while (num[last] == '0') last--;

                if (num[last] != '.')
                    while(i < last) {
                        num[i] = num[i+1];
                        i++;
                        d++;
                    }
                if (start < 0) start = 0;
                if (removed) while(num[start] == '0') start++;
            }
        }

        num = string(num.begin()+start, num.begin()+last);
        if (num.empty()) num = "0";
        return d;
    }

    bool int_compare(string num1, string num2) {
        /** return true if num1 > num2 else false **/
        return num1.length() != num2.length() ? num1.length() > num2.length() : num1 > num2;
    }

    bool compare(string& num1, string& num2, int& d) {

        int d1(digit(num1, true)), d2(digit(num2, true));
        d = max(d1, d2);
        if (num1 == "0") return false;
        if (num2 == "0") return true;
        d1 < d2 ? num1 += string(d2-d1, '0') : num2 += string(d1-d2, '0');

        return int_compare(num1, num2);
    }

    bool compare_val(string num1, string num2) {

        int d1(digit(num1)), d2(digit(num2));
        int d = max(d1, d2);

        d1 < d2 ? num1 += string(d2-d1, '0') : num2 += string(d1-d2, '0');

        return int_compare(num1, num2);
    }

    bool is_op(const char& c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    bool is_digit(const char& c) {
        return c >= '0' && c <= '9' || c == '.';
    }

    bool is_number(string str) {
        int decimal = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') continue;
            else if (str[i] == '.') decimal++;
            else return false;
        }
        return decimal < 2;
    }

    string abs(string num) {
        if (num[0] == '-') num[0] = '0';
        return num;
    }

    string add(string num1, string num2, const char op='+') {

        /**
            num1 / num2: non-negative, could be decimal
            op: the sign of ans
        **/

        string ans;
        if (op == '-') ans += '-';

        int d1(digit(num1, true)), d2(digit(num2, true)), d(max(d1, d2));
        d1 < d2 ? num1 += string(d2 - d1, '0') : num2 += string(d1 - d2, '0');

        if (num1.length() < num2.length())
            swap(num1, num2);

        int n1(num1.length()), n2(num2.length()), s(max(n1, d + 1) + 1), sum[s]({});

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

        reverse(sum, sum + s);

        for (int i = (!sum[0]); i < s; ++i) {
            ans += sum[i] + '0';
            if (d && i + d == s - 1)
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

        int n1(num1.length()), n2(num2.length()), s(max(n1, d + 1)), diff[s]({});

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n1; ++i) {
            i < n2 ? diff[i] += num1[i] - num2[i] : diff[i] += num1[i] - '0';

            if (diff[i] < 0) {
                diff[i] += 10;
                diff[i+1]--;
            }
        }

        reverse(diff, diff + s);

        bool flag = true;

        for (int i = 0; i < s; ++i) {
            if (!diff[i] && i + d < s - 1 && flag)
                continue;
            flag = false;
            if (i + d == s)
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

        /** num1 multiplies num2 **/

        string ans;

        if ((num1[0] == '-')^(num2[0] == '-')) ans += '-';

        int d1(digit(num1, true)), d2(digit(num2, true)), d(d1 + d2);

        if (num1 == "0" || num2 == "0") return "0";

        int n1(num1.length()), n2(num2.length()), s(max(n1, d1 + 1) + max(n2, d2 + 1)), product[s]({});

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < n2; ++j) {
                product[i+j] += (num1[i] - '0') * (num2[j] - '0');
                if (product[i+j] > 9) {
                    product[i+j+1] += product[i+j]/10;
                    product[i+j] %= 10;
                }
            }


        for (int i = 0; i < s - 1; ++i) {
            product[i+1] += product[i] / 10;
            product[i] %= 10;
        }

        reverse(product, product + s);

        for (int i = (!product[0]); i < s; ++i) {
            if (i + d == s) ans += '.';
            ans += product[i] + '0';
        }

        return ans;
    }

    string divide(string num1, string num2, bool zeros=true) {

        string ans;

        if ((num1[0] == '-')^(num2[0] == '-')) ans += '-';

        int d1(digit(num1, true)), d2(digit(num2, true));

        if (num2 == "0") return "Error: divisor cannot be zero";
        if (num1 == "0") return "0";

        d1 < d2 ? num1 += string(d2-d1, '0') : num2 += string(d1-d2, '0');

        if (zeros) num1 += string(p, '0');
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
        } else if (p) {
            res.insert(res.end()-p, '.');
        }

        ans += res;
        return ans;
    }

    string factorial(string num) {
        if (num[0] == '-') return "Error: n must be non-negative";
        if (digit(num))    return "Error: n must be an integer";

        string ans = "1";

        while (num != "0") {
            ans = multiply(ans, num);
            num = subtract(num, "1");
        }

        return ans;
    }

    string permutation(string n, string r) {
        if (n[0] == '-' || r[0] == '-') return "Error: n and r must be non-negative";
        if (digit(n) || digit(r)) return "Error: n and r must be integers";
        if (int_compare(r, n)) return "Error: r cannot be greater than n";

        string base = r;
        string ans = "1";

        while (base != n) {
            base = add(base, "1");
            ans = multiply(ans, base);
        }

        return ans;
    }

    string combination(string n, string r) {
        if (n[0] == '-' || r[0] == '-') return "Error: n and r must be non-negative";
        if (digit(n) || digit(r))       return "Error: n and r must be integers";
        if (int_compare(r, n))          return "Error: r cannot be greater than n";

        string s = subtract(n, r);
        return int_compare(s, r) ? combination(n, s) : divide(permutation(n, r), factorial(s), false);
    }

    string int_power(string num1, string num2) {
        string bi = base(num2, 10, 2, true);

        string base = num1;
        string res = "1";

        for (int i = 0; i < bi.length(); ++i) {
            if (bi[i] - '0')
                res = multiply(res, base);
            if (i != bi.length() - 1)
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
        string ans = int_power(e, string(num.begin(), num.end()-d));

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
            flag ? ans = pm(ans, term, '+') : ans = pm(ans, term, '-');
            flag = !flag;
            x = multiply(num, x);
            i = add(i, "1");
            digit(term, true);
        }

        return ans;
    }

    void compute_ln2() {
        ln2 = "0.6931471805599";
    }

    string ln(string num) {

        if (num[0] == '-') return "Error: n must be positive";

        string k("0");
        int d = digit(num);
        if (num == "0") return "Error: n must be positive";
        if (d) num.insert(num.end()-d, '.');

        if (ln2.empty()) compute_ln2();
        while (compare_val(num, "1.5")) {
            num = divide(num, "2");
            k = add(k, "1");
        }

        return add(multiply(k, ln2), ln02(num));
    }

    string power(string num1, string num2) {
        if (num2[0] == '-') {
            num2[0] = '0';
            string temp(power(num1, num2));
            return temp.substr(0, 5) == "Error" ? temp : divide("1", temp);
        }

        bool ng(num1[0] == '-');
        int d1(digit(num1)), d2(digit(num2));
        if (d1) num1.insert(num1.end()-d1, '.');

        if (d2) {
            num2.insert(num2.end()-d2, '.');
            return num1 == "0" ? "0" : ng ? "Error: complex numbers" : exp(multiply(ln(num1), num2));
        } else {
            return num1 == "0" ? num2 == "0" ? "Error: 0^0 undefined" : "1" : int_power(num1, num2);
        }
    }

    string log(string a, string b) {
        return divide(ln(b), ln(a));
    }

    void calculate_pi() {
        string temp = "0";
        string k = "0";
        string term;
        string ans = "0";
        bool flag = true;
        while (term != "0") {

            term = divide(multiply(permutation(multiply("6", k), multiply("3", k)), add(multiply("545140134", k), "13591409")),
                          multiply(int_power(factorial(k), "3"), power("640320", add(multiply("3", k), "1.5"))));
            flag ? ans = pm(ans, term, '+') : ans = pm(ans, term, '-');
            flag = !flag;
            k = add(k, "1");
            digit(term);
        }
        pi = divide("1", multiply("12", ans));
        //cout << temp_pi << endl;
        //pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
        half_pi = divide(pi, "2");
        double_pi = multiply(pi, "2");
    }

    string sin(string num) {
        if (pi.empty())
            calculate_pi();

        if (num[0] == '-') {
            num[0] = '0';
            return "-" + sin(num);
        }

        while (compare_val(num, double_pi))
            num = pm(num, double_pi, '-');

        if (compare_val(num, pi)) {
            return "-" + sin(pm(num, pi, '-'));
        } else if (compare_val(num, half_pi)) {
            return sin(pm(pi, num, '-'));
        }

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
        return sin(pm(half_pi, num, '-'));
        /**
        if (num[0] == '-') {
            num[0] = '0';
            return cos(num);
        }

        while (num > 2 * pi) {
            num = pm(num, double_pi, '-');
        }

        if (num > pi) {
            return cos(pm(double_pi, num, '-'));
        } else if (num > pi/2) {
            return "-" + cos(pm(pi, num, '-'));
        }

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
        **/
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
            string t2 = multiply(int_power("4", i), add(k, "1"));
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

    string simplify(string& eq) {
        /** edit later **/
        int comma(0), decimal(0);

        for (int i = 0; i < eq.length(); ++i) {
            if (eq[i] == ',') comma++;
            else if (eq[i] == '.') decimal++;
            else if (is_op(eq[i])) decimal = 0;
            if (decimal > 1) return "Error: extra decimal points";
        }
        if (comma) return "comma";
        if (is_op(*eq.rbegin())) return "Error: invalid expression";
        if (eq[0] == '*' || eq[0] == '/' || eq[0] == '^') return "Error: invalid expression";

        for (int i = 1; i < eq.length() - 1; ++i) {
            if (is_op(eq[i-1]) && is_op(eq[i])) {
                if (eq[i] == '+') {
                        if (eq[i-1] == '+') {
                            eq[i] = eq[i-1];
                            eq[i-1] = ' ';
                        } else if (is_op(eq[i+1])) {
                            eq[i] = eq[i-1];
                            eq[i-1] = ' ';
                        } else {
                            eq[i] = '0';
                        }
                } else if (eq[i] == '-') {
                    if ((eq[i-1] == '+' || eq[i-1] == '-') && is_op(eq[i+1])) {
                        eq[i-1] == '+' ? eq[i] = '-' : eq[i] = '+';
                        eq[i-1] = 0;
                    }
                } else {
                    return "Error: invalid expression";
                }
            }
        }
        // remove blanks;
        if (eq[0] == '+') eq.insert(eq.begin(), '0');
        else if (eq[0] == '-' && eq[1] == '-') eq.insert(eq.begin(), '0');
        return "0";
    }

    string inner(string eq) {
        // Error Handlers
        string code = simplify(eq);
        if (code.substr(0, 5) == "Error") return code;
        else if (code == "comma") return eq;
        eq += "+0";

        deque<string> nums;
        queue<char> ops;
        stack<string> pows;

        nums.push_back("");
        nums.back() += eq[0];

        for (int i = 1; i < eq.length(); ++i) {
            if (is_digit(eq[i]))  {
                if (nums.empty())
                    nums.push_back("");
                else if (is_op(eq[i-1]) && nums.back() != "-")
                    nums.push_back("");
                nums.back() += eq[i];
            } else if (eq[i] == '^') {
                pows.push(nums.back());
                nums.pop_back();
            } else {
                if (!pows.empty() && eq[i-1] != '^') {
                    pows.push(nums.back());
                    nums.pop_back();
                    while (pows.size() > 1) {
                        string temp = pows.top();
                        pows.pop();
                        pows.top() = power(pows.top(), temp);
                        if (pows.top().substr(0, 5) == "Error")
                            return pows.top();
                    }
                    nums.push_back(pows.top());
                    pows.pop();
                }
                is_op(eq[i-1]) ? nums.push_back("-") : ops.push(eq[i]);
            }
        }

        int k(ops.size());

        while (k--) {
            if (ops.front() == '*' || ops.front() == '/') {
                string temp1 = nums.front();
                nums.pop_front();
                string temp2 = nums.front();
                nums.pop_front();

                ops.front() == '*' ? nums.push_front(multiply(temp1, temp2)) : nums.push_front(divide(temp1, temp2));
                if (nums.front().substr(0, 5) == "Error") return nums.front();
                ops.pop();
            } else {
                nums.push_back(nums.front());
                nums.pop_front();
                ops.push(ops.front());
                ops.pop();
            }
        }

        nums.push_back(nums.front());
        nums.pop_front();

        while (!ops.empty()) {
            string temp1 = nums.front();
            nums.pop_front();
            string temp2 = nums.front();
            nums.pop_front();

            nums.push_front(pm(temp1, temp2, ops.front()));
            ops.pop();
        }
        //cout << "ans: " << nums.back() << endl;
        return nums.back();
    }

    string special(string spec, string num) {

        string fs[12] = {"factorial", "npr", "ncr", "exp", "ln", "log",
                         "sin", "cos", "tan", "asin", "acos", "atan"};
        int k(0);
        while(fs[k++] != spec)
            if (k == 12) return "Error: special function undefined";

        switch (k) {
            case 1: return factorial(num);
            case 4: return exp(num);
            case 5: return ln(num);
            case 7: return sin(num);
            case 8: return cos(num);
            case 9: return tan(num);
            case 10: return asin(num);
            case 11: return acos(num);
            case 12: return atan(num);
            default: {
                int comma(-1);
                for (int i = 0; i < num.length(); ++i)
                    if (num[i] == ',') {
                        comma = i;
                        break;
                    }
                if (comma == -1) return "Error: invalid expression";
                string n1(num.begin(), num.begin() + comma), n2(num.begin()+comma+1, num.end());
                if (!is_number(n1) || !is_number(n2)) return "Error: invalid expression";
                return k == 2 ? permutation(n1, n2) : k == 3 ? combination(n1, n2) : log(n1, n2);
            }
        }
    }

    string eval(string eps) {
        stack<string> bkts;
        string spec;

        bkts.push("");

        for (int i = 0; i < eps.length(); ++i) {
            if (eps[i] == ' ') continue;

            if (is_op(eps[i]) || is_digit(eps[i]) || eps[i] == ',') {
                bkts.top() += eps[i];
            } else if (eps[i] == '(') {
                bkts.push("");
            } else if (eps[i] == ')') {
                if (bkts.size() < 2)
                    return "Error: extra right brackets";
                string temp = inner(bkts.top());
                if (temp.substr(0, 5) == "Error")
                    return temp;
                bkts.pop();
                if (is_digit(*bkts.top().rbegin()))
                    bkts.top() += '*';
                if (!spec.empty()) {
                    temp = special(spec, temp);
                    spec.clear();
                }
                if (temp.substr(0, 5) == "Error")
                    return temp;
                if (!is_number(temp)) return "Error: invalid expression";
                bkts.top() += temp;
            } else if (eps[i] >= 'a' && eps[i] <= 'z'){
                spec += eps[i];
            } else {
                return "Error: invalid expression";
            }
        }

        if (bkts.size() > 1)
            return "Error: extra left brackets";
        return inner(bkts.top());
    }
};

int main() {
    Calculator c(20);
    string str;

    string num1 = ".", num2 = "0.023";
    char op = '+';
    string n = ".003";
    cout << num1 << endl;
    string t = c.ln("4");
    cout << t << endl;
    return 0;
}
