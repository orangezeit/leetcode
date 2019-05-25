int lengthOfLongestSubstring(string s) {

    unordered_set<char> list;
    int maxL(0), l(0);

    for (int i = 0; i < s.length(); ++i) {
        if (list.find(s[i]) == list.end()) {
            list.insert(s[i]);
            l++;
        } else {
            maxL = max(maxL, l);

            while (s[i-l] != s[i]) {
                list.erase(s[i-l]);
                l--;
            }

        }
    }

    return max(maxL, l);
}
