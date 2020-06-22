class Solution {
public:
    bool checkValidString(string s) {
        int max_op(0), min_op(0);
        for (int i = 0; i < s.length(); ++i) {
            s[i] == '(' ? min_op++ : min_op--;
            s[i] != ')' ? max_op++ : max_op--;
            min_op = max(min_op, 0);
            if (max_op < 0) return false;
        }

        return min_op == 0;
    }
};
