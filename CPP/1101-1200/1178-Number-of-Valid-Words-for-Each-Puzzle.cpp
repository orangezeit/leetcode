class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        vector<int> bp(puzzles.size()), ans(puzzles.size());

        for (int i = 0; i < words.size(); ++i) {
            int x(0);
            for (const char c: words[i]) {
                x |= 1 << (c - 'a');
            }
            freq[x]++;
        }
        int k(0);
        for (string s: puzzles) {

            const int l = s.length() - 1;

            for (int i = 0; i < (1 << l); ++i) {
                int mark = 1 << (s[0] - 'a');
                for (int j = 0; j < l; ++j)
                    if (i & (1 << j)) mark |= 1 << (s[j + 1] - 'a');
                if (freq.count(mark))
                    ans[k] += freq[mark];
            }
            k++;
        }
        return ans;
    }
};
