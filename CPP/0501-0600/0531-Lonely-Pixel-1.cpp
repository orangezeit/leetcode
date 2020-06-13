class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int h(picture.size()), w(picture[0].size()), c(0);
        vector<int> hs(h, 0);
        vector<int> ws(w, 0);

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (picture[i][j] == 'B') {
                    hs[i]++;
                    ws[j]++;
                }
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (hs[i] == 1 && ws[j] == 1) {
                    ws[j] = 0;
                    c++;
                }

            }
        }

        return c;
    }
};
