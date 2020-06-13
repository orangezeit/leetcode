class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        queue<int> q;
        q.push(start[0] * n + start[1]);
        unordered_set<int> visited; // node, minimum dist

        while (!q.empty()) {

            int s = q.size();

            while (s--) {
                int p = q.front();
                q.pop();

                int i(p / n), j(p % n);

                while (--i >= 0 && maze[i][j] == 0) {};
                ++i;

                if (!visited.count(i * n + j)) {
                    visited.insert(i * n + j);
                    q.push(i * n + j);
                }

                i = p / n;
                j = p % n;

                while (++i < m && maze[i][j] == 0) {};
                --i;

                if (!visited.count(i * n + j)) {
                    visited.insert(i * n + j);
                    q.push(i * n + j);
                }

                i = p / n;
                j = p % n;

                while (--j >= 0 && maze[i][j] == 0) {};
                ++j;

                if (!visited.count(i * n + j)) {
                    visited.insert(i * n + j);
                    q.push(i * n + j);
                }

                i = p / n;
                j = p % n;

                while (++j < n && maze[i][j] == 0) {};
                --j;

                if (!visited.count(i * n + j)) {
                    visited.insert(i * n + j);
                    q.push(i * n + j);
                }
            }
        }

        return visited.count(destination[0] * n + destination[1]);
    }
};
