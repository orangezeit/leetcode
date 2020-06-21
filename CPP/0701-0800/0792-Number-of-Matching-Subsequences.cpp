class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        sort(words.begin(), words.end());
        int i(0), ans(0), n(words.size());

        while (i < n) {
            int j(i), k(0);
            for (const char& c: s) {
                if (k == words[i].length()) break;
                if (c == words[i][k]) k++;
            }
            while(j < n - 1 && words[j] == words[j + 1]) j++;
            if (k == words[i].length()) ans += j + 1 - i;
            i = j + 1;
        }

        return ans;
    }
};
