class Solution {
public:
    bool test(const string& s1, const string& s2, int first1, int last1, int first2, int last2) {
        //cout << first1 << " " << last1 << " " << first2 << " " << last2 << endl;
        if (first1 == last1 && first2 == last2) return s1[first1] == s2[first2];

        for (int len = 1; len <= last1 - first1; ++len) {
            unordered_map<int, int> counters;
            bool isEmpty(true);

            for (int i = 0; i < len; ++i) {
                if (!(++counters[s1[first1 + i]])) counters.erase(s1[first1 + i]);
                if (!(--counters[s2[first2 + i]])) counters.erase(s2[first2 + i]);
            }
            isEmpty &= counters.empty();
            counters.clear();
            for (int i = len; i <= last1 - first1; ++i) {
                if (!(++counters[s1[first1 + i]])) counters.erase(s1[first1 + i]);
                if (!(--counters[s2[first2 + i]])) counters.erase(s2[first2 + i]);
            }
            isEmpty &= counters.empty();
            counters.clear();
            if (isEmpty) {
                bool a = test(s1, s2, first1, first1 + len - 1, first2, first2 + len - 1);
                bool b = test(s1, s2, first1 + len, last1, first2 + len, last2);
                if (a && b) return true;
            }
            isEmpty = true;
            for (int i = 0; i < len; ++i) {
                if (!(++counters[s1[first1 + i]])) counters.erase(s1[first1 + i]);
                if (!(--counters[s2[last2 - len + 1 + i]])) counters.erase(s2[last2 - len + 1 + i]);
            }
            isEmpty &= counters.empty();
            counters.clear();
            for (int i = len; i <= last1 - first1; ++i) {
                if (!(++counters[s1[first1 + i]])) counters.erase(s1[first1 + i]);
                if (!(--counters[s2[first2 + i - len]])) counters.erase(s2[first2 + i - len]);
            }
            isEmpty &= counters.empty();
            counters.clear();
            if (isEmpty) {
                bool c = test(s1, s2, first1, first1 + len - 1, last2 - len + 1, last2);
                bool d = test(s1, s2, first1 + len, last1, first2, last2 - len);
                if (c && d) return true;
            }

        }

        return false;
    }
    bool isScramble(string s1, string s2) {
        int n(s1.length());
        return test(s1, s2, 0, n - 1, 0, n - 1);
    }
};
