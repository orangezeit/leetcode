class Solution {
public:
    string find(string s, unordered_map<string, string>& acctUni) {
        if (s != acctUni[s])
            acctUni[s] = find(acctUni[s], acctUni);
        return acctUni[s];
    }

    void unite(string s, string t, unordered_map<string, string>& acctUni) {
        string ps = find(s, acctUni);
        string pt = find(t, acctUni);

        if (ps != pt) {
            acctUni[pt] = ps;
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, string> gp;
        unordered_map<string, double> vals;

        for (int i = 0; i < values.size(); ++i) {

            if (gp.find(equations[i][0]) == gp.end())
                gp[equations[i][0]] = equations[i][0];
            if (gp.find(equations[i][1]) == gp.end())
                gp[equations[i][1]] = equations[i][1];

            if (vals.find(equations[i][0]) == vals.end() && vals.find(equations[i][1]) == vals.end()) {
                vals[equations[i][0]] = values[i];
                vals[equations[i][1]] = 1.0;
            } else if (vals.find(equations[i][0]) == vals.end()) {
                vals[equations[i][0]] = vals[equations[i][1]] * values[i];
            } else if (vals.find(equations[i][1]) == vals.end()) {
                vals[equations[i][1]] = vals[equations[i][0]] / values[i];
            } else {

                double n = vals[equations[i][1]];

                for (auto it = gp.begin(); it != gp.end(); ++it) {
                    if (it->second == equations[i][1])
                        vals[it->first] /= n * values[i];
                }
            }
            unite(equations[i][0], equations[i][1], gp);
        }

        for (auto it = gp.begin(); it != gp.end(); ++it)
            find(it->first, gp);

        vector<double> res(queries.size(), -1.0);

        for (int i = 0; i < res.size(); ++i)
            if (!gp[queries[i][0]].empty() && !gp[queries[i][1]].empty())
                if (gp[queries[i][0]] == gp[queries[i][1]])
                    res[i] = vals[queries[i][0]] / vals[queries[i][1]];

        return res;
    }
};
