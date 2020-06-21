class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_set<int> visited;
        vector<int> delays(N, 10000);


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;

        q.push({0, K});
        delays[K-1] = 0;

        while (!q.empty()) {
            int distance = q.top().first;
            int node = q.top().second;
            q.pop();

            delays[node-1] = distance;
            //cout << distance << " " << node << endl;
            visited.insert(node);

            if (visited.size() == N) {
                break;
            }

            for (int i = 0; i < times.size(); ++i) {
                if (times[i][0] == node && visited.find(times[i][1]) == visited.end()) {
                    //delays[times[i][1] - 1] = min(delays[times[i][1] - 1], times[i][2] + distance);
                    q.push({times[i][2] + distance, times[i][1]});
                }
            }



        }

        int res = 0;

        for (int i = 0; i < delays.size(); ++i) {
            //cout << delays[i] << " ";
            if (delays[i] == 10000) {
                return -1;
            } else {
                res = max(res, delays[i]);
            }
        }

        return res;
    }
};
