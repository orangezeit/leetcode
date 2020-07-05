class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st1, st2;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st1.push(i);
            else if (s[i] == ')')
                st1.empty() ? st2.push(i) : st1.pop();
        }

        while (!st1.empty() || !st2.empty()) {
            int a = st1.empty() ? -1 : st1.top();
            int b = st2.empty() ? -1 : st2.top();
            if (a > b) {
                s.erase(s.begin() + a);
                st1.pop();
            } else if (b > a) {
                s.erase(s.begin() + b);
                st2.pop();
            }
        }

        return s;
    }
};
