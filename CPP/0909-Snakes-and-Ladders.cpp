class Solution {
public:
    pair<int, int> indices(int steps, const int& len, const int& w) {
        int x = steps / w;
        int y = steps % w;
        return {len - x - 1, (x % 2 ? w - y - 1 : y)};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int len = board.size();
        int w = board[0].size();

        queue<int> q;
        q.push(1);
        int steps(1);
        unordered_set<int> shortcuts;

        while (!q.empty()) {
            int s = q.size();

            while (s--) {
                int loc = q.front();
                q.pop();

                int idx = -1;

                for (int i = 1; i <= 6; ++i) {
                    if (loc + i > len * w) continue;
                    if (loc + i == len * w) return steps;

                    pair<int, int> p = indices(loc + i - 1, len, w);
                    if (board[p.first][p.second] == -1) {
                        idx = i;
                    } else if (!shortcuts.count(loc + i)) {
                        if (board[p.first][p.second] == len * w) return steps;
                        q.push(board[p.first][p.second]);
                        shortcuts.insert(loc + i);
                    }

                }
                if (idx != -1) q.push(loc + idx);
            }
            ++steps;
        }

        return -1;
    }
};
