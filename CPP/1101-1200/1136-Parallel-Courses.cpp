class Solution {
public:
    unordered_map<int, int> visited;

    int traverse(unordered_map<int, unordered_set<int>>& rec, int i, unordered_set<int>& path) {
        if (path.find(i) != path.end()) return -1;
        if (visited.find(i) != visited.end()) return visited[i];

        visited[i] = 1;

        for (const auto& r: rec[i]) {
            path.insert(i);
            int d = traverse(rec, r, path);
            if (d == -1)
                return visited[i] = -1;
            else
                visited[i] = max(visited[i], d + 1);
            path.erase(i);

        }

        return visited[i];
    }

    int minimumSemesters(int N, vector<vector<int>>& relations) {

        unordered_map<int, unordered_set<int>> rec;
        unordered_set<int> heads;

        for (int i = 1; i <= N; ++i)
            heads.insert(i);

        for (const vector<int>& r: relations) {
            rec[r[0]].insert(r[1]);
            heads.erase(r[1]);
        }

        unordered_set<int> path;
        int ans(-1);

        for (const int& h: heads)
            ans = max(ans, traverse(rec, h, path));

        return ans;
    }
};
