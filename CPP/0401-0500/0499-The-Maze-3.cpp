class Solution {
public:
    unordered_map<int, pair<int, string>> visited; // node, minimum dist

    bool verify(int i, int j, int n, int c, string path) {
        if (!visited.count(i * n + j)) return true;
        if (visited[i * n + j].first > c) return true;
        if (visited[i * n + j].first == c && path < visited[i * n + j].second) return true;
        return false;
    }

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        const int m = maze.size();
        const int n = maze[0].size();

        queue<pair<pair<int, int>, string>> q;
        q.push({{ball[0] * n + ball[1], 0}, ""});


        int minDist(INT_MAX);
        string ans("impossible");
        const int h = hole[0] * n + hole[1];

        while (!q.empty()) {

            int s = q.size();

            while (s--) {
                pair<int, int> p = q.front().first;
                string path = q.front().second;

                q.pop();

                int i(p.first / n), j(p.first % n);
                bool fall(false), enter(false);
                path += 'u';

                while (--i >= 0 && maze[i][j] == 0) {
                    enter = true;
                    if (i * n + j == h) {
                        fall = true;
                        if (p.second + p.first / n - i < minDist) {
                            minDist = p.second + p.first / n - i;
                            ans = path;
                            //cout << ans << " a" << endl;
                        } else if (p.second + p.first / n - i == minDist) {
                            ans = min(ans, path);
                            //cout << ans << " b" << endl;
                        }
                        break;
                    }
                };

                ++i;
                int c = p.second + p.first / n - i;
                if (enter && !fall && verify(i, j, n, c, path)) {
                    visited[i * n + j] = {c, path};
                    q.push({{i * n + j, c}, path});
                }

                path.pop_back();

                i = p.first / n;
                j = p.first % n;
                fall = false;
                enter = false;
                path += 'd';

                while (++i < m && maze[i][j] == 0) {
                    enter = true;
                    if (i * n + j == h) {
                        fall = true;
                        if (p.second + i - p.first / n < minDist) {
                            minDist = p.second + i - p.first / n;
                            ans = path;
                            //cout << ans << "_a" <<  endl;
                        } else if (p.second + i - p.first / n == minDist) {
                            ans = min(ans, path);
                            //cout << ans << "_b" << endl;
                        }
                        break;
                    }
                };

                --i;

                c = p.second + i - p.first / n;
                if (enter && !fall && verify(i, j, n, c, path)) {
                    visited[i * n + j] = {c, path};
                    q.push({{i * n + j, c}, path});
                }

                path.pop_back();

                i = p.first / n;
                j = p.first % n;
                fall = false;
                enter = false;
                path += 'l';

                while (--j >= 0 && maze[i][j] == 0) {
                    enter = true;
                    if (i * n + j == h) {
                        fall = true;
                        if (p.second + p.first % n - j < minDist) {
                            minDist = p.second + p.first % n - j;
                            ans = path;
                            //cout << ans << "*a" << endl;
                        } else if (p.second + p.first % n - j == minDist) {
                            //cout << "*path " << path << endl;
                            ans = min(ans, path);
                            //cout << ans << "*b" << endl;
                        }
                        break;
                    }
                };
                ++j;

                c = p.second + p.first % n - j;
                if (enter && !fall && verify(i, j, n, c, path)) {
                    visited[i * n + j] = {c, path};
                    q.push({{i * n + j, c}, path});
                }

                path.pop_back();

                i = p.first / n;
                j = p.first % n;
                fall = false;
                enter = false;
                path += 'r';

                while (++j < n && maze[i][j] == 0) {
                    enter = true;
                    if (i * n + j == h) {
                        fall = true;
                        if (p.second + j - p.first % n < minDist) {
                            minDist = p.second + j - p.first % n;
                            ans = path;
                            //cout << ans << "-a" << endl;
                        } else if (p.second + j - p.first % n == minDist) {
                            ans = min(ans, path);
                            //cout << ans << "-b" << endl;
                        }
                        break;
                    }
                };

                --j;
                c = p.second + j - p.first % n;
                if (enter && !fall && verify(i, j, n, c, path)) {
                    visited[i * n + j] = {c, path};
                    q.push({{i * n + j, c}, path});
                }
            }
        }

        return ans;
    }
};
