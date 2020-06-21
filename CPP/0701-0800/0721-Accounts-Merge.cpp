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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> acctUni;
        unordered_map<string, string> name;           // email: name

        for (int i = 0; i < accounts.size(); ++i) {
            name[accounts[i][1]] = accounts[i][0];

            for (int j = 1; j < accounts[i].size(); ++j)
                if (acctUni.find(accounts[i][j]) == acctUni.end())
                    acctUni[accounts[i][j]] = accounts[i][j];

            for (int j = 2; j < accounts[i].size(); ++j) {
                unite(accounts[i][1], accounts[i][j], acctUni);
            }
        }

        unordered_map<string, set<string>> res;

        for (auto it = acctUni.begin(); it != acctUni.end(); ++it) {
            res[find(it->first, acctUni)].insert(it->first);
        }

        vector<vector<string>> ans(res.size());
        int k = -1;

        for (auto it = res.begin(); it != res.end(); ++it) {
            ans[++k].push_back(name[it->first]);
            for (auto jt = it->second.begin(); jt != it->second.end(); ++jt) {
                ans[k].push_back(*jt);
            }
        }

        return ans;
    }
};
