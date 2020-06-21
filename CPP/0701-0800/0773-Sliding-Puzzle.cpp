class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string puzzle(6, '0');

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                puzzle[i * 3 + j] += board[i][j];

        queue<string> q({puzzle});
        unordered_set<string> past({puzzle});

        int steps(0);
        int dirs[5] = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                string temp = q.front();
                q.pop();

                if (temp == "123450") return steps;

                for (int i = 0; i < 6; ++i) {
                    if (temp[i] - '0') continue;

                    for (int j = 0; j < 4; ++j) {
                        int ni = i / 3 + dirs[j];
                        int nj = i % 3 + dirs[j + 1];

                        if (ni < 0 || ni >= 2 || nj < 0 || nj >= 3) continue;
                        swap(temp[i], temp[ni * 3 + nj]);
                        if (!past.count(temp)) {
                            q.push(temp);
                            past.insert(temp);
                        }
                        swap(temp[i], temp[ni * 3 + nj]);
                    }

                    break;
                }
            }
            ++steps;
        }

        return -1;
    }
};
