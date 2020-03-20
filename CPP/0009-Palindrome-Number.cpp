class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        auto it(str.begin()), jt(str.end());
        while (it < jt) if (*(it++) != *(--jt)) return false;
        return true;
    }
};
