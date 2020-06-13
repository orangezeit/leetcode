class Solution {
public:
    map<int, set<set<int>>> rec;
    int m, n;

    void modify(const set<int>& island, const int& k) {
        // {x, -y}, {-x, y}, {-x, -y}, {y, x}, {-y, x}, {y, -x}, {-y, -x}
        vector<pair<int, int>> lefttop(7, {INT_MAX, INT_MAX});
        vector<set<pair<int, int>>> record(7);

        for (const int& i: island) {
            int x(i / n), y(i % n);

            record[0].insert({x, -y});
            lefttop[0].first = min(lefttop[0].first, x);
            lefttop[0].second = min(lefttop[0].second, -y);

            record[1].insert({-x, y});
            lefttop[1].first = min(lefttop[1].first, -x);
            lefttop[1].second = min(lefttop[1].second, y);

            record[2].insert({-x, -y});
            lefttop[2].first = min(lefttop[2].first, -x);
            lefttop[2].second = min(lefttop[2].second, -y);

            record[3].insert({y, x});
            lefttop[3].first = min(lefttop[3].first, y);
            lefttop[3].second = min(lefttop[3].second, x);

            record[4].insert({-y, x});
            lefttop[4].first = min(lefttop[4].first, -y);
            lefttop[4].second = min(lefttop[4].second, x);

            record[5].insert({y, -x});
            lefttop[5].first = min(lefttop[5].first, y);
            lefttop[5].second = min(lefttop[5].second, -x);

            record[6].insert({-y, -x});
            lefttop[6].first = min(lefttop[6].first, -y);
            lefttop[6].second = min(lefttop[6].second, -x);
        }

        for (int i = 0; i < 7; ++i) {
            set<int> newIsland;
            for (const pair<int, int>& p: record[i])
                newIsland.insert((p.first - lefttop[i].first) * n + (p.second - lefttop[i].second));
            rec[k].insert(newIsland);
        }
    }

    void floodfill(vector<vector<int>>& grid, int x, int y, set<pair<int, int>>& island, int& left, int& top, int& k) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (grid[x][y] == 0 || grid[x][y] == 2) return;

        left = min(left, x);
        top = min(top, y);
        k++;
        island.insert({x, y});
        grid[x][y] = 2;

        floodfill(grid, x - 1, y, island, left, top, k);
        floodfill(grid, x, y - 1, island, left, top, k);
        floodfill(grid, x + 1, y, island, left, top, k);
        floodfill(grid, x, y + 1, island, left, top, k);
    }

    int numDistinctIslands2(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans(0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    set<pair<int, int>> xys;
                    int left(INT_MAX), top(INT_MAX), k(0);
                    floodfill(grid, i, j, xys, left, top, k);

                    set<int> island;
                    for (const pair<int, int>& p: xys) {
                        island.insert((p.first - left) * n + (p.second - top));
                    }
                    if (!rec[k].count(island)) {
                        ans++;
                        rec[k].insert(island);
                        modify(island, k);
                    }

                }
            }
        }

        return ans;
    }
};
