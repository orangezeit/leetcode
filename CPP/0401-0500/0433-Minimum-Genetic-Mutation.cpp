class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({start, 0});
        vector<bool> visited(bank.size(), false);

        while (!q.empty()) {
            string str = q.front().first;
            int k = q.front().second;
            q.pop();

            for (int i = 0; i < bank.size(); ++i) {
                if (!visited[i]) {
                    int c = 0;

                    for (int j = 0; j < str.length(); ++j) {
                        if (str[j] != bank[i][j]) {
                            c++;
                            if (c == 2) {
                                break;
                            }
                        }
                    }

                    if (c == 1) {
                        if (bank[i] == end) {
                            return k+1;
                        } else {
                            q.push({bank[i], k + 1});
                            visited[i] = true;
                        }
                    }
                }
            }
        }

        return -1;
    }
};
