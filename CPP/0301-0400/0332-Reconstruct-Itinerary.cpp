class Solution {
    typedef unordered_map<string, priority_queue<string, vector<string>, greater<string>>> GraphType;
public:
    void travel(vector<string>& ans, string curr, GraphType& g) {
        auto& v = g[curr];
        while (!v.empty()) {
            string next = v.top();
            v.pop();
            travel(ans, next, g);
        }
        ans.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        GraphType g;
        for (const vector<string>& edge: tickets)
            g[edge[0]].push(edge[1]);
        vector<string> ans;
        travel(ans, "JFK", g);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
