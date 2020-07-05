class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans(0);
        vector<int> c(26, 0);
        for (int i = 0; i < chars.length(); ++i)
            c[chars[i] - 'a']++;

        for (int i = 0; i < words.size(); ++i) {
            vector<int> d(26, 0);
            ans += words[i].length();
            for (int j = 0; j < words[i].length(); ++j) {
                d[words[i][j] - 'a']++;
                if (d[words[i][j] - 'a'] > c[words[i][j] - 'a']) {
                    ans -= words[i].length();
                    break;
                }
            }
        }

        return ans;
    }
};
