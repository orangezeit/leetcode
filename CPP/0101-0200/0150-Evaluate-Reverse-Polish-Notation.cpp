    static bool isOperator(string str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
    
    int calculate (int num1, int num2, string op) {
        if (op == "+") {
            return num1 + num2;
        } else if (op == "-") {
            return num1 - num2;
        } else if (op == "*") {
            return num1 * num2;
        } else {
            return num1 / num2;
        }
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> subtokens;
        int i(0);
        
        while (i < tokens.size()) {
            if (isOperator(tokens[i])) {
                int num2 = subtokens.top();
                subtokens.pop();
                int num1 = subtokens.top();
                subtokens.pop();
                subtokens.push(calculate(num1, num2, tokens[i++]));
            } else {
                subtokens.push(stoi(tokens[i++]));
            }
        }

        return subtokens.top();
    }
