class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_set<int> visited = {id};
        unordered_map<string, int> cnts;
        queue<int> q;
        q.push(id);
        int steps = 1;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int nid = q.front();
                q.pop();
                for (int f: friends[nid]) {
                    if (visited.count(f)) continue;
                    if (steps == level) {
                        for (string v: watchedVideos[f]) {
                            cnts[v]++;
                        }
                    }
                    q.push(f);
                    visited.insert(f);
                }
            }
            if (steps == level) break;
            steps++;
        }

        vector<pair<int, string>> pa(cnts.size());
        int k = 0;
        for (const auto& p: cnts) {
            pa[k].first = p.second;
            pa[k].second = p.first;
            k++;
        }
        sort(pa.begin(), pa.end());
        vector<string> ans(cnts.size());
        for (int i = 0; i < cnts.size(); ++i) {
            ans[i] = pa[i].second;
        }

        return ans;
    }
};
