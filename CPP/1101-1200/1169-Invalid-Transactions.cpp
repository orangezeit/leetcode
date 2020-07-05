class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        // name: { {{time, location}, index} }
        unordered_map<string, set< pair<pair<int, string>, int> >> rec;
        unordered_set<string> ans;
        int n(0);

        for (string& ts: transactions) {
            ts += ',';
            int k(0), idx(0);
            // name, time, amount, location
            vector<string> infos(4);

            for (int i = 0; i < ts.length(); ++i) {
                if (ts[i] == ',') {
                    infos[idx++] = ts.substr(k, i - k);
                    k = i + 1;
                }
            }
            ts.pop_back();
            int time(stoi(infos[1])), amount(stoi(infos[2]));
            rec[infos[0]].insert({{time, infos[3]}, n});

            if (amount > 1000) {
                ans.insert(ts);

            } //else {

                auto it = rec[infos[0]].find({{time, infos[3]}, n});

                while (it != rec[infos[0]].begin()) {
                    --it;
                    if ((*it).first.first + 60 < time) {
                        break;
                    }

                    if ((*it).first.second != infos[3]) {
                        ans.insert(ts);
                        ans.insert(transactions[(*it).second]);
                    }

                }

                it = rec[infos[0]].find({{time, infos[3]}, n});
                ++it;

                while (it != rec[infos[0]].end()) {
                    if ((*it).first.first - 60 > time) {
                        break;
                    }

                    if ((*it).first.second != infos[3]) {
                        ans.insert(ts);
                        ans.insert(transactions[(*it).second]);
                    }
                    ++it;
                }
            n++;
        }

        return vector<string>(ans.begin(), ans.end());
    }
};
