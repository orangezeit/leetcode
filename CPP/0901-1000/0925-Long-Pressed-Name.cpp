class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i(0), j(0), n(name.length()), t(typed.length());
        name += '*';
        typed += '*';
        while (i < n && j < t) {
            int x(i), y(j);
            if (name[i] != typed[j]) return false;
            while (name[i] == name[++i]) {};
            while (typed[j] == typed[++j]) {};
            if (i - x > j - y) return false;
        }

        return i == n && j == t;

    }
};
