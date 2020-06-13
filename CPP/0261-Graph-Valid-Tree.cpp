class Solution {
public:
    unordered_map<int, unordered_set<int>> record;
    bool traverse(int curr, unordered_set<int> path) {
        //cout << curr << endl;
        if (path.find(curr) != path.end()) return false;
        path.insert(curr);
        //nodes.insert(curr);
        for (auto it = record[curr].begin(); it != record[curr].end(); ++it) {
            record[*it].erase(curr);
            if (!traverse(*it, path)) return false;
        }
        record.erase(curr);
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> path;
        for (int i = 0; i < edges.size(); ++i) {
            record[edges[i][0]].insert(edges[i][1]);
            record[edges[i][1]].insert(edges[i][0]);
        }
        if (n == 1 && edges.size() == 0) return true;
        if (record.size() < n) return false;
        if (!traverse(0, path)) return false;
        if (!record.empty()) return false;
        return true;
    }
};
