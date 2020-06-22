class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int m(heightMap.size()), n(heightMap[0].size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i * n});
            pq.push({heightMap[i][n-1], i * n + n - 1});
            heightMap[i][0] = -1; heightMap[i][n-1] = -1;
        }

        for (int j = 1; j < n - 1; ++j) {
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[m-1][j], m * n - n + j});
            heightMap[0][j] = -1; heightMap[m-1][j] = -1;
        }

        int maxHeight = INT_MIN;
        int res(0);
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            maxHeight = max(maxHeight, temp.first);

            for (int i = 0; i < 4; ++i) {
                int newi = temp.second / n + dirs[i][0];
                int newj = temp.second % n + dirs[i][1];

                if (newi < 0 || newi >= m || newj < 0 || newj >= n) continue;
                if (heightMap[newi][newj] == -1) continue;
                res += max(maxHeight - heightMap[newi][newj], 0);

                pq.push({heightMap[newi][newj], newi * n + newj});
                heightMap[newi][newj] = -1;
            }
        }

        return res;
    }
};
