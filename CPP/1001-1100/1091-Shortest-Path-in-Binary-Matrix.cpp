class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        int side = grid.size();
        if (side == 1) return 1;

        int dirs[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        unordered_set<int> visited = {0};
        queue<int> q;
        q.push(0);
        int steps(2);

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int xy = q.front();
                q.pop();

                for (int i = 0; i < 8; ++i) {
                    int nx = xy / side + dirs[i][0];
                    int ny = xy % side + dirs[i][1];

                    if (nx < 0 || nx >= side || ny < 0 || ny >= side) continue;
                    if (grid[nx][ny]) continue;
                    if (visited.count(nx * side + ny)) continue;
                    if (nx * side + ny == side * side - 1) return steps;
                    q.push(nx * side + ny);
                    visited.insert(nx * side + ny);
                }
            }
            ++steps;
        }

        return -1;
    }
};
