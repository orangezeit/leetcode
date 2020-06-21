class Solution {
public:
    bool canTransform(string start, string end) {
        int l(0), r(0), x(0);
        for (const char& c: start) c == 'L' ? l++ : c == 'R' ? r++ : x++;
        for (const char& c: end) c == 'L' ? l-- : c == 'R' ? r-- : x--;
        if (l || r || x) return false;

        int i(0), j(0), n(start.length());

        while (i < n && j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;
            if (i < n ^ j < n) return false;
            if (i < n && j < n)
                if (start[i] != end[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                    return false;
            i++;
            j++;
        }

        return true;
    }
};
