class Solution {
public:
    int m, n;
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({start[0] * n + start[1], 0});
        unordered_map<int, int> visited; // node, minimum dist

        while (!q.empty()) {

            int s = q.size();

            while (s--) {
                pair<int, int> p = q.front();
                q.pop();

                int i(p.first / n), j(p.first % n);

                while (--i >= 0 && maze[i][j] == 0) {};
                ++i;

                if (!visited.count(i * n + j) || visited[i * n + j] > p.second + p.first / n - i) {
                    visited[i * n + j] = p.second + p.first / n - i;
                    q.push({i * n + j, p.second + p.first / n - i});
                }

                i = p.first / n;
                j = p.first % n;

                while (++i < m && maze[i][j] == 0) {};
                --i;

                if (!visited.count(i * n + j) || visited[i * n + j] > p.second + i - p.first / n) {
                    visited[i * n + j] = p.second + i - p.first / n;
                    q.push({i * n + j, p.second + i - p.first / n});
                }

                i = p.first / n;
                j = p.first % n;

                while (--j >= 0 && maze[i][j] == 0) {};
                ++j;

                if (!visited.count(i * n + j) || visited[i * n + j] > p.second + p.first % n - j) {
                    visited[i * n + j] = p.second + p.first % n - j;
                    q.push({i * n + j, p.second + p.first % n - j});
                }

                i = p.first / n;
                j = p.first % n;

                while (++j < n && maze[i][j] == 0) {};
                --j;

                if (!visited.count(i * n + j) || visited[i *  n + j] > p.second + j - p.first % n) {
                    visited[i * n + j] = p.second + j - p.first % n;
                    q.push({i * n + j, p.second + j - p.first % n});
                }
            }
        }

        int d = destination[0] * n + destination[1];
        return visited.count(d) ? visited[d] : -1;
    }
};
