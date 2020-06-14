class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, unordered_set<int>> rec;
        for (int i = 0; i < ppid.size(); ++i) {
            rec[ppid[i]].insert(pid[i]);
        }
        deque<int> ans = {kill};
        queue<int> q;
        q.push(kill);

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int curr = q.front();
                q.pop();

                for (const int& node: rec[curr]) {
                    q.push(node);
                    ans.push_back(node);
                }

            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};
