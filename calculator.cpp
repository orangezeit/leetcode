#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm> // reverse


using namespace std;

class Calculator {
//private:
public:
    string pi = "3.1415926";

    string based(string num, int n, int m) {
        const string labels = "0123456789abcdefghijklmnopqrstuvwxyz";
        vector<int> digits;

        reverse(num.begin(), num.end());

        for (int i = 0; i < num.size(); ++i) {

        }

    }

    int digit(string& num) {

        /*** detect the decimal if exists and remove extra zeros from both sides ***/

        int start = 0;
        if (num[start] == '-') start++;
        while (num[start] == '0') start++;

        for (int i = start; i < num.length(); ++i) {
            if (num[i] == '.') {
                int t = 0;
                int last = num.length() - 1;

                if (num[start] == '.') start--;
                while (num[last] == '0') last--;

                if (num[last] != '.')
                    while(i < last) {
                        num[i] = num[i+1];
                        i++;
                        t++;
                    }

                num = string(num.begin()+start, num.begin()+last);
                //cout << "t" << endl;
                return t;
            }
        }

        num = string(num.begin()+start, num.end());
        if (num.empty())
            num = "0";
        return 0;
    }

    bool int_compare(string num1, string num2) {
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
            num1 and num2: non-negative, could be decimal
            op: the sign that applies to ans
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
            num1 / num2: non-negative, integer
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

        for (int i = 0; i < n1; ++i) {
            if (!diff[i] && i + d < n1 - 1)
                continue;
            if (i + d == n1)
                ans += '.';
            ans += diff[i] + '0';
        }

        return ans;
    }

    string pm(string n1, string n2, char op) {

        /** num1 add or subtract num2 **/

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

    string divide(string num1, string num2, const int p=0, const int r=-1) { // slow
        //cout << num1 << " " << num2 << endl;
        string ans;

        if ((num1[0] == '-')^(num2[0] == '-'))
            ans += '-';

        int d1(digit(num1)), d2(digit(num2));
        if (int_compare(num2, num1)) return "0";

        d1 < d2 ? num1 += string(d2-d1, '0') : num2 += string(d1-d2, '0');

        num1 += string(p+1, '0');
        //cout << num1 << " *** " << num2 << endl;
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
                //cout << res << endl;
            }

            res = subtract(res, pre);
            inter = subtract(inter, multiply(pre, num2));
            pre = "1";
            base = "1";
            ext = subtract(num1, inter);
            //cout << "ni" << num1 << " " << inter << endl;
            //cout << "c" << ext << endl;
            //if (ext == num2) break;
        }

        if (ext == num2)
            res = add(res, "1");
        ans += res;
        ans.erase(ans.end()-1);
        if (p)
        ans.insert(ans.end()-p, '.');

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

        while(base != n) {
            base = add(base, "1");
            ans = multiply(ans, base);
        }

        return ans;
    }

    string combination(string n, string r) {
        string s = subtract(n, r);
        return int_compare(s, r) ? combination(n, s) : divide(permutation(n, r), factorial(s));
    }

    string totwo(string num, bool reversed=false) {
        string b;
        while(num != "0") {
            (num[num.length() - 1] - '0') % 2 ? b += '1' : b += '0';
            num = divide(num, "2");
            cout << num << endl;
        }
        if (reversed)
            reverse(b.begin(), b.end());
        return b;
    }

    string int_power(string num1, string num2, int d) {
        string bin = totwo(num2);
        if (d)
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

    string exp(string num, int p) {
        //return "1";
        int d(digit(num));
        string e = "0." + string(p-1, '0') + "1";
cout << e << endl;
        string index = "1";
        string term = "1";
        string ans = "1";
        string eh = "1";
        int k = 0;
        cout << int_power(num, index, d) << endl;
/*
        while (compare(eh, e, k)) {
            term = divide(int_power(num, index, d), factorial(index), p * 2);
            ans = add(ans, term);
            index = add(index, "1");
            eh = abs(term);
        }
*/
        return ans;
    }

    string ln(string num, int p) {
        return "1";
    }

    string power(string num1, string num2) {
        int p = 1;

        if (num2[0] == '-') {
            num2[0] = '0';
            return divide("1", power(num1, num2), p);
        }

        bool ng(num1[0] == '-');
        int d1(digit(num1)), d2(digit(num2));

        if (d2) {
            //return num1 != "0" ? ng1 ? "Error" : exp(multiply(ln(num1, p), num2), p) : "0";
        } else {
            //return num1 == "0" ? num2 == "0" ? "Error" : "1" : int_power(num1, num2, d1);
        }
    }

    string log(string a, string b, int p) {
        return divide(ln(b, p), ln(a, p), p);
    }

    string sin(string num, int p) {
        string e = "0." + string(p-1, '0') + "1";

        string index = "1";
        string term = "1";
        string ans = "0";
        string eh = num;
        bool flag = true;
        int d = 0;
        //return "a";
        while (compare(eh, e, d)) {
            term = divide(power(num, index), factorial(index), p * 2);
            flag ? ans = add(ans, term) : ans = subtract(ans, term);
            flag = !flag;
            index = add(index, "2");
            eh = abs(term);
            //cout << "k" << " " << ans << endl;
        }
        //cout << "a";
        return ans;
    }

    string cos(string num, int p) {
        string zeros(p-1, '0');
        string e = "0." + zeros + "1";

        string index = "2";
        string term = "1";
        string ans = "1";
        string eh = "1";
        bool flag = false;
        int d = 0;
        //return "a";
        while (compare(eh, e, d)) {
            term = divide(power(num, index), factorial(index), p * 2);
            flag ? ans = add(ans, term) : ans = subtract(ans, term);
            flag = !flag;
            index = add(index, "2");
            eh = abs(term);
            //cout << "k" << " " << ans << endl;
        }
        //cout << "a";
        return ans;
    }

    string tan(string num, int p) {
        return divide(sin(num, p), cos(num, p), p);
    }

    string asin(string num, int p) {
        string e = "0." + string(p-1, '0') + "1";

        string index = "1";
        string term = "1";
        string ans = "0";
        string eh = num;
        bool flag = true;
        int d = 0;
        //return "a";
        while (compare(eh, e, d)) {
            term = divide(power(num, index), factorial(index), p * 2);
            flag ? ans = add(ans, term) : ans = subtract(ans, term);
            flag = !flag;
            index = add(index, "2");
            eh = abs(term);
            //cout << "k" << " " << ans << endl;
        }
        //cout << "a";
        return ans;
    }

    string acos(string num, int p) {
        return pm(divide(pi, "2"), asin(num, p), '-');
    }

    string atan(string num, int p) {
        string e = "0." + string(p-1, '0') + "1";

        string index = "1";
        string term = "1";
        string ans = "0";
        string eh = num;
        bool flag = true;
        int d = 0;
        //return "a";
        while (compare(eh, e, d)) {
            term = divide(power(num, index), index, p * 2);
            flag ? ans = add(ans, term) : ans = subtract(ans, term);
            flag = !flag;
            index = add(index, "2");
            eh = abs(term);
            //cout << "k" << " " << ans << endl;
        }
        //cout << "a";
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
    string str;
    //cin >> str;
    //cout << c.eval(str) << endl;

    string num1 = "1.23", num2 = "5.00";
    char op = '+';
    string test = c.divide("22", "2");
    //string num3 = "-0000.0002300400";
    //string t = c.add("0.23", "5.00", op);
    cout << test << endl;
    return 0;
}
