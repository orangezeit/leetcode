class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m(image.size()), n(image[0].size()), left(y), right(y), up(x), down(x);
        queue<int> q;
        unordered_set<int> visited;
        visited.insert(x * n + y);
        q.push(x * n + y);
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int loc = q.front();
                q.pop();

                int i(loc / n), j(loc % n);
                for (int k = 0; k < 4; ++k) {
                    int ni(i + dirs[k][0]), nj(j + dirs[k][1]);
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (image[ni][nj] == '0') continue;
                    if (visited.count(ni * n + nj)) continue;

                    up = min(up, ni);
                    down = max(down, ni);
                    left = min(left, nj);
                    right = max(right, nj);

                    q.push(ni * n + nj);
                    visited.insert(ni * n + nj);
                }
            }
        }
        //cout << left << " " << right << endl;
        return (right - left + 1) * (down - up + 1);
    }
};
