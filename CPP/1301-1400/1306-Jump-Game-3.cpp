class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // bfs
        if (arr[start] == 0) return true;
        unordered_set<int> visited = {start};
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            for (int i : {idx-arr[idx], idx+arr[idx]}) {
                if (i < 0 || i >= arr.size()) continue;
                if (visited.count(i)) continue;
                if (arr[i] == 0) return true;
                q.push(i);
                visited.insert(i);
            }
        }

        return false;
    }
};
