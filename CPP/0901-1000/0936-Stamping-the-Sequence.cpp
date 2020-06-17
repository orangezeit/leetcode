class Solution {
public:
    bool equal(int i, string& target, const string& stamp, int& cnt) {
        int c(0);
        for (int k = 0; k < stamp.length(); ++k) {
            if (target[i + k] == '?') c++;
            else if (target[i + k] != stamp[k]) return false;
        }
        if (c == stamp.length()) return false;
        cnt += stamp.length() - c;
        for (int k = 0; k < stamp.length(); ++k)
            target[i + k] = '?';
        return true;
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int cnt(0);

        while (cnt != target.length()) {
            bool enter(false);
            for (int i = 0; i <= target.length() - stamp.length(); ++i) {
                if (equal(i, target, stamp, cnt)) {
                    enter = true;
                    ans.push_back(i);
                    i += stamp.length() - 1;

                }
            }
            if (!enter) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
