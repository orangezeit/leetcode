class Solution {
public:
    vector<int> lp;
    bool fp;
    void traverse(int curr, int parent, unordered_map<int, vector<int>>& tree, int d, int& md, int& en, vector<int>& path) {

        for (const int& next: tree[curr]) {
            if (next != parent) {
                if (fp) path.push_back(next);
                traverse(next, curr, tree, d + 1, md, en, path);
                if (fp) path.pop_back();
            }
        }

        md = max(md, d);

        if (d == md) {
            en = curr;
            if (fp) lp = path;
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return {0};
        unordered_map<int, vector<int>> tree;
        for (const vector<int>& edge: edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        vector<int> path;
        int x(0), y(0), md(0);

        fp = false;
        traverse(0, -1, tree, 0, md, x, path);

        fp = true;
        path.push_back(x);
        traverse(x, -1, tree, 0, md, y, path);

        int a((lp.size() - 1) / 2), b(a + 1 + !(lp.size() % 2));
        return vector<int>(lp.begin() + a, lp.begin() + b);
    }
};
