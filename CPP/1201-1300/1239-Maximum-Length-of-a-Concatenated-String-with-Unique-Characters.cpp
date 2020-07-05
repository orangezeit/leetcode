class Solution {
public:
    void concatenate(const vector<int>& bits, int curr, int c, int& ans) {
        bool test(true);
        for (int i = curr; i < bits.size(); ++i) {
            int temp = c ^ bits[i];

            if ((temp & c) == c && (temp & bits[i]) == bits[i]) {
                test = false;
                concatenate(bits, i + 1, temp, ans);
            }
        }


        if (test) {
            int k(0);
            while (c) {
                k += c & 1;
                c >>= 1;
            }
            ans = max(ans, k);
        }

    }
    int maxLength(vector<string>& arr) {
        vector<int> bits(arr.size());
        int k(arr.size());
        int j(0);

        for (const string& str: arr) {
            vector<bool> letters(26, false);
            bool finished(true);

            for (const char& c: str) {
                if (letters[c - 'a']) {
                    k--;
                    finished = false;
                    break;
                } else
                    letters[c - 'a'] = true;
            }

            if (finished) {
                for (int i = 0; i < 26; ++i)
                    if (letters[i])
                        bits[j] += 1 << i;
                j++;
            }

        }

        bits.resize(k);
        int ans(0);
        concatenate(bits, 0, 0, ans);

        return ans;
    }
};
