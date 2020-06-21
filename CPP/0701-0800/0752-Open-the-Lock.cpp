class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        if (deads.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        int steps(1);
        unordered_set<string> visited = {"0000"};

        while (!q.empty()) {
            int s = q.size();

            while (s--) {
                string curr = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int d = curr[i] - '0';

                    curr[i] = (++d)-- % 10 + '0';
                    if (curr == target) return steps;
                    if (!visited.count(curr) && !deads.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }

                    curr[i] = ((--d)++ + 10) % 10 + '0';
                    if (curr == target) return steps;
                    if (!visited.count(curr) && !deads.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }

                    curr[i] = d + '0';
                }
            }

            steps++;
        }

        return -1;
    }
};
