class Solution {
public:
    string minWindow(string s, string t) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        unordered_map<char, int> mt;
        for (const char& c: t) mt[c]++;

        int k = 0;
        string ans;
        int cnt(0);

        for (int i = 0; i < s.length(); ++i) {
            if (mt.find(s[i]) != mt.end()) {
                mt[s[i]]--;
                cnt++;
                if (mt[s[i]] <= 0) {
                    while (!mt.count(s[k]) || mt[s[k]] < 0) {
                        if (mt.count(s[k]) && mt[s[k]] < 0) {
                            mt[s[k]]++;
                            cnt--;
                        }
                        k++;
                    }
                }

                if (cnt >= t.length()) {
                    bool verified(true);
                   for (const auto& p: mt)
                       if (p.second > 0) {
                           verified= false;
                           break;
                       }
                    if (verified && (ans.empty() || ans.length() > i - k + 1)) {
                        ans = s.substr(k, i - k + 1);
                    }

                }
            }
        }

        return ans;
    }
};
