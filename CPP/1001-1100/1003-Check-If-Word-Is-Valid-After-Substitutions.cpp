class Solution {
public:
    bool isValid(string S) {
        stack<string> stk;
        int k = 0;

        while (k < S.length()) {
            if (S[k] == 'a') {
                stk.push("a");
            } else if (stk.empty()) {
                return false;
            } else if (S[k] == 'b' && stk.top() == "a") {
                stk.top() = "ab";
            } else if (S[k] == 'c' && stk.top() == "ab") {
                stk.pop();
            } else {
                return false;
            }
            k++;
        }

        return stk.empty();
    }
};
