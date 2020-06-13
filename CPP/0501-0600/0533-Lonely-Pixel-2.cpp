class Solution {
public:
    bool isSame(const vector<vector<char>>& picture, const unordered_set<int>& indices, const int& n) {
        auto it = indices.begin(), jt = next(it);

        while (jt != indices.end()) {
            for (int i = 0; i < n; ++i) {
                if (picture[*it][i] != picture[*jt][i])
                    return false;
            }
            ++it;
            ++jt;
        }

        return true;
    }

    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m(picture.size()), n(picture[0].size()), ans(0);

        for (int i = 0; i < m; ++i) {
            int c(0);
            unordered_set<int> indices;
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'W') continue;
                if (++c > N) break;
                indices.insert(j);
            }
            if (c != N) continue;
            for (const int& j: indices)
                picture[i][j] = 'X';
        }
        /*
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << picture[i][j] << " ";
            } cout << endl;
        }*/
        for (int j = 0; j < n; ++j) {
            int c(0);
            unordered_set<int> indices;
            for (int i = 0; i < m; ++i) {
                if (picture[i][j] == 'W') continue;
                if (picture[i][j] == 'B' || (++c > N)) {
                    indices.clear();
                    break;
                }
                //cout << c << endl;
                indices.insert(i);
            }
            if (indices.size() != N) continue;
            //for (int i: indices) cout << i << " ";
            //cout << endl;
            //if (!indices.empty()) {
            //cout << indices.size()
                if (isSame(picture, indices, n))
                    ans += N;
            //}
        }

        return ans;
    }
};
