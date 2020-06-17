class Solution {
private:
    vector<int> f;

    void fill(int s) {
        f.resize(s+1);
        f[0] = 1;
        for (int i = 1; i <= s; ++i)
            f[i] = i * f[i-1];
    }

public:
    void helper(vector<int> letters, vector<int> combines, int start, int len, int& cnt) {
        if (len == 0) {
            int prod = 1;
            int sum = 0;

            for (int i = 0; i < 26; ++i)
                if (combines[i]) {
                    prod *= f[combines[i]];
                    sum += combines[i];
                }

            cnt += f[sum] / prod;
        } else {
            for (int i = start; i < 26; ++i) {
                int s = min(letters[i], len);
                for (int k = 1; k <= s; ++k) {
                    letters[i] -= k;
                    combines[i] += k;
                    helper(letters, combines, i+1, len-k, cnt);
                    letters[i] += k;
                    combines[i] -= k;
                }
            }
        }


    }

    int numTilePossibilities(string tiles) {
        fill(tiles.length());

        vector<int> letters(26, 0);
        vector<int> combines(26, 0);
        int ans(0);

        for (int i = 0; i < tiles.length(); ++i)
            letters[tiles[i] - 'A']++;

        for (int i = 1; i <= tiles.length(); ++i)
            helper(letters, combines, 0, i, ans);

        return ans;
    }
};
