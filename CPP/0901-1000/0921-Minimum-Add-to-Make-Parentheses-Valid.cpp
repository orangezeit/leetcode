class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> brackets;

        for (int i = 0; i < S.length(); ++i) {
            if (brackets.empty()) {
                brackets.push(S[i]);
            } else if (brackets.top() == '(' && S[i] == ')') {
                brackets.pop();
            } else if (brackets.top() == '[' && S[i] == ']') {
                brackets.pop();
            } else if (brackets.top() == '{' && S[i] == '}') {
                brackets.pop();
            } else {
                brackets.push(S[i]);
            }
        }

        return brackets.size();
    }
};
