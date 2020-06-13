class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, int> indegrees;
        unordered_map<int, unordered_set<int>> path;

        // iterate and build the map
        for (const auto& p: seqs) {
            if (p.empty()) continue;
            indegrees[p.back()];

            for (int i = 0; i + 1 < p.size(); ++i) {
                indegrees[p[i]];
                if (!path[p[i]].count(p[i + 1]))
                    indegrees[p[i + 1]]++;
                path[p[i]].insert(p[i + 1]);
            }
            //cout << 'a';
        }

        if (indegrees.size() != org.size()) return false;
        //cout << 'a';
        // find the number of nodes with 0-indegree
        bool start(false);
        int point(0);
        for (const auto& [k, v]: indegrees) {
            if (v == 0) {
                start = true;
                point = k;
            }
        }
        //cout << start << endl;
        if (!start) return false;

        queue<int> q;
        q.push(point);
        int idx(0);

        while (!q.empty()) {

            int x = q.front();
            q.pop();
            //cout << x << endl;
            if (idx == org.size() || org[idx] != x) return false;

            idx++;
            for (const int& nxt: path[x])
                if (!(--indegrees[nxt]))
                    q.push(nxt);
            //cout << q.size() << endl;
            if (q.size() > 1) return false;
        }

        return idx == org.size();
    }
};
