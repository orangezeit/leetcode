class Solution {
public:
    int evaluate(string expression) {
        scopes_.clear();
        int pos = 0;
        return eval(expression, pos);
    }
private:
    int eval(const string& s, int& pos) {
        scopes_.push_front(unordered_map<string, int>());
        int value = 0; // The return value of current expr
        if (s[pos] == '(') ++pos;

        // command, variable or number
        const string token = getToken(s, pos);

        if (token == "add") {
            int v1 = eval(s, ++pos);
            int v2 = eval(s, ++pos);
            value = v1 + v2;
        } else if (token == "mult") {
            int v1 = eval(s, ++pos);
            int v2 = eval(s, ++pos);
            value = v1 * v2;
        } else if (token == "let") {
            string var;
            // expecting " var1 exp1 var2 exp2 ... last_expr)"
            while (s[pos] != ')') {
                ++pos;
                // Must be last_expr
                if (s[pos] == '(') {
                    value = eval(s, ++pos);
                    break;
                }
                // Get a token, could be "x" or "-12" for last_expr
                var = getToken(s, pos);
                // End of let, var is last_expr
                if (s[pos] == ')') {
                    if (isalpha(var[0]))
                        value = getValue(var);
                    else
                        value = stoi(var);
                    break;
                }
                // x -12 -> set x to -12 and store in the current scope and take it as the current return value
                value = scopes_.front()[var] = eval(s, ++pos);
            }
        } else if (isalpha(token[0])) {
            value = getValue(token); // symbol
        } else {
            value = std::stoi(token); // number
        }
        if (s[pos] == ')') ++pos;
        scopes_.pop_front();
        return value;
    }

    int getValue(const string& symbol) {
        for (const auto& scope : scopes_)
            if (scope.count(symbol)) return scope.at(symbol);
        return 0;
    }

    // Get a token from current pos.
    // "let x" -> "let"
    // "-12 (add x y)" -> "-12"
    string getToken(const string& s, int& pos) {
        string token;
        while (pos < s.length()) {
            if (s[pos] == ')' || s[pos] == ' ') break;
            token += s[pos++];
        }
        return token;
    }

    deque<unordered_map<string, int>> scopes_;
};
