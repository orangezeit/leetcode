class Solution {
public:
    bool parse(const string& exp, int& s) {
        char c = exp[s++];

        if (c == 't') return true;
        if (c == 'f') return false;

        s++;

        if (c == '!') {
            bool temp = !parse(exp, s);
            s++;
            return temp;
        }

        bool is_and = c == '&';
        bool ans = is_and;

        while (true) {
            is_and ? ans &= parse(exp, s) : ans |= parse(exp, s);
            if (exp[s++] == ')') break;
        }

        return ans;
    }
    bool parseBoolExpr(string expression) {
        int s = 0;
        return parse(expression, s);
    }
};
