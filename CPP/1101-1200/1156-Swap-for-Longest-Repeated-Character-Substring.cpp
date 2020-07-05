class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> cnts(26);
        for (const char& c: text)
            cnts[c - 'a']++;

        int start = -1;
        int ans(1);

        while (++start < text.length()) {
            int end = start + 1;
            char c = text[start];
            bool swapped = false;

            while (end < text.length() && (!swapped || text[end] == c) && end - start < cnts[c - 'a'])
                if (text[end++] != c)
                    swapped = true;

            ans = max(ans, end - start);
        }

        return ans;
    }
};
