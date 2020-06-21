class Solution {
public:
    vector<int> parse(const string& log) {
        vector<int> info(3);
        int i = 0;
        while(log[++i] != ':') {}
        info[0] = stoi(log.substr(0, i));
        int k = ++i;
        while(log[++i] != ':') {}
        info[1] = log.substr(k, i-k) == "start";
        info[2] = stoi(log.substr(++i));
        return info;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int, int>> s;
        int t(0);
        for (int i = 0; i < logs.size(); ++i) {
            vector<int> p = parse(logs[i]); // id, start(end), time
            if (p[1]) {
                if (!s.empty()) ans[s.top().first] += p[2] - s.top().second;
                s.push({p[0], p[2]}); // id, start
            } else {
                ans[s.top().first] += p[2] - s.top().second + 1;
                s.pop();
                if(!s.empty()) s.top().second = p[2] + 1;
            }
        }
        return ans;
    }
};
