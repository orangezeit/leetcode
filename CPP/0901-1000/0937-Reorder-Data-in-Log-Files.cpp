class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int k = logs.size() - 1;

        while (k >= 0) {
            int c(0);
            while (logs[k][c++] != ' ') {}
            if (isdigit(logs[k][c]))
                k--;
            else
                break;
        }

        for (int i = k - 1; i >= 0; --i) {
            int c = 0;
            while (logs[i][c++] != ' ') {}
            if (isdigit(logs[i][c])) swap(logs[i], logs[k--]);
        }

        sort(logs.begin(), logs.begin() + k + 1,
             [](const string& s, const string& t) {
                 int i(0), j(0);

                while(s[i++] != ' ') {}
                while(t[j++] != ' ') {}

                while (s[i] == t[j]) {
                    if (++i == s.length()) {
                        return true;
                    } else if (++j == t.length()) {
                        return false;
                    }
                }

                return s[i] < t[j];
             });
        return logs;
    }
};
