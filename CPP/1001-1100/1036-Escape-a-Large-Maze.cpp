class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int steps(0);
        const long start((long)source[0] * 1000000 + source[1]), end((long)target[0] * 1000000 + target[1]);
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        unordered_set<long> blocks, visited({start}), visited2({end});

        for (const vector<int>& b: blocked)
            blocks.insert((long)b[0] * 1000000 + b[1]);

        queue<long> q;
        q.push(start);

        while (!q.empty() && steps <= blocked.size()) {
            int s = q.size();
            while (s--) {
                long idx = q.front();
                q.pop();
                long x(idx / 1000000), y(idx % 1000000);

                for (int i = 0; i < 4; ++i) {
                    long newx(x + dirs[i][0]), newy(y + dirs[i][1]);
                    if (newx < 0 || newx >= 1000000 || newy < 0 || newy >= 1000000) continue;

                    if (visited.count(newx * 1000000 + newy)) continue;
                    if (blocks.count(newx * 1000000 + newy)) continue;
                    if (newx * 1000000 + newy == end) return true;
                    q.push(newx * 1000000 + newy);
                    visited.insert(newx * 1000000 + newy);
                }
            }
            steps++;
        }

        if (q.empty()) return false;

        queue<long> q2;
        q2.push(end);
        steps = 0;

        while (!q2.empty() && steps <= blocked.size()) {
            int s = q2.size();
            while (s--) {
                long idx = q2.front();
                q2.pop();
                long x(idx / 1000000), y(idx % 1000000);

                for (int i = 0; i < 4; ++i) {
                    long newx(x + dirs[i][0]), newy(y + dirs[i][1]);
                    if (newx < 0 || newx >= 1000000 || newy < 0 || newy >= 1000000) continue;

                    if (visited2.count(newx * 1000000 + newy)) continue;
                    if (blocks.count(newx * 1000000 + newy)) continue;
                    if (visited.count(newx * 1000000 + newy)) return true;
                    q2.push(newx * 1000000 + newy);
                    visited2.insert(newx * 1000000 + newy);
                }
            }
            steps++;
        }

        return !q2.empty();
    }
};
