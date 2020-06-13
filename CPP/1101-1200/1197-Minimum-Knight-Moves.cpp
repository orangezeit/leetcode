class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (!x && !y) return 0;
        unordered_map<int, unordered_set<int>> board;

        queue<pair<int, int>> q;
        q.push({0, 0});
        int dirs[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        board[0].insert(0);
        int steps = 1;

        while (true) {
            int s = q.size();

            while (s--) {
                pair<int, int> p = q.front();

                q.pop();

                for (int i = 0; i < 8; ++i) {
                    int newx = p.first + dirs[i][0];
                    int newy = p.second + dirs[i][1];
                    if (newx == x && newy == y) return steps;
                    // make sure the dirs are right
                    if (!(board.count(newx) && board[newx].count(newy)) && newx * x >= 0 && newy * y >= 0) {
                        q.push({newx, newy});
                        board[newx].insert(newy);
                    }
                }
            }

            ++steps;
        }

        return -1;
    }
};
