class Solution {
public:
    bool isReversed(string s, string t) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != t[t.length() - 1 - i])
                return false;
        }
        return true;
    }

    int longestDecomposition(string text) {
        int i = 0;
        int j = text.length() - 1;
        string left, right;
        int ans(0);

        while (i <= j) {
            if (i == j) {
                ans++;
                break;
            }
            left += text[i++];
            right += text[j--];

            if (isReversed(left, right)) {
                //cout << left << " " << right << endl;
                ans += 2;
                left.clear();
                right.clear();
            }
        }
        if (i > j && !left.empty()) ans++;
        return ans;
    }
};
