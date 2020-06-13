class Solution {
public:
    string parseTernary(string expression) {
        stack<char> tf;
        tf.push(expression.back());

        // reversed expression and parse easier
        for (int i = expression.length() - 3; i >= 0; i -= 2) {
            if (expression[i + 1] == ':') {
                tf.push(expression[i]);
            } else {
                if (expression[i] == 'F') {
                    tf.pop();
                } else {
                    char c = tf.top();
                    tf.pop();
                    tf.pop();
                    tf.push(c);
                }
            }
        }

        return string(1, tf.top());
    }
};
