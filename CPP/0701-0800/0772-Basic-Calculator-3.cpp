class Solution {
public:
    string equate(string s) {
        s += "+0";
        deque<long> nums;
        deque<char> ops;

        string n;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                n += s[i];
            } else {
                if (i == 0 || s[i-1] < '0' || s[i-1] > '9') {
                    n += s[i];
                } else {
                    nums.push_back(stol(n));
                    n.clear();

                    if (!ops.empty())
                        while (ops.back() == '*' || ops.back() == '/') {
                            long temp = nums.back();
                            nums.pop_back();
                            ops.back() == '*' ? nums.back() *= temp : nums.back() /= temp;
                            ops.pop_back();
                            if (ops.empty()) break;
                        }

                    ops.push_back(s[i]);

                }

            }
        }

        nums.push_back(stoi(n));

        long ans(nums.front());
        nums.pop_front();

        while (!ops.empty()) {
            ops.front() == '+' ? ans += nums.front() : ans -= nums.front();
            nums.pop_front();
            ops.pop_front();
        }

        return to_string(ans);
    }

    int calculate(string s) {
        stack<string> eqs;
        eqs.push("");

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') continue;
            if (s[i] == '(') {
                eqs.push("");
            } else if (s[i] == ')') {
                string temp = equate(eqs.top());
                eqs.pop();
                eqs.top() += temp;
            } else {
                eqs.top() += s[i];
            }
        }
        //cout << eqs.top();
        return stoi(equate(eqs.top()));
    }
};
