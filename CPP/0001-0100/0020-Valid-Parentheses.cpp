class Solution {
public:
    bool isValid(string s) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        stack<char> brackets;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                brackets.push(s[i]);
            } else if (brackets.empty()) {
                return false;
            } else if (brackets.top() == '(' && s[i] == ')') {
                brackets.pop();
            } else if (brackets.top() == '[' && s[i] == ']') {
                brackets.pop();
            } else if (brackets.top() == '{' && s[i] == '}') {
                brackets.pop();
            } else {
                return false;
            }
        }

        return brackets.empty();
    }
};
