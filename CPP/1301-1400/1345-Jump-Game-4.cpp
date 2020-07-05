class Solution {
public:
    int minJumps(vector<int>& arr) {
        // bfs
        int steps(0);
        vector<int> visited(arr.size());
        unordered_map<int, vector<int>>  m;
        for (int i = 0; i < arr.size(); ++i)
            m[arr[i]].push_back(i);
        visited[0] = 1;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int curr = q.front();
                q.pop();

                if (curr + 1 == arr.size()) return steps;

                if (curr && !visited[curr - 1]) {
                    q.push(curr - 1);
                    visited[curr - 1] = 1;
                }
                if (!visited[curr + 1]) {
                    q.push(curr + 1);
                    visited[curr + 1] = 1;
                }
                for (const int& i: m[arr[curr]]) {
                    if (arr[i] == arr[curr] && !visited[i]) {
                        q.push(i);
                        visited[i] = 1;
                    }
                }
                m.erase(arr[curr]);
            }
            ++steps;
        }

        return -1;
    }
};
