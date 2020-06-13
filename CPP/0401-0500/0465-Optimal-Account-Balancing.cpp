class Solution {
public:
    void dfs(vector<int>& payers, vector<int>& payees, int cnt, int& minCnt) {
        //if (minCnt != INT_MAX) return;
        bool enter=false;
        for (int& payer: payers) {
            if (payer) {
                for (int& payee: payees) {
                    if (payee) {
                        enter = true;
                        int c = max(payer, -payee);
                        payee += c;
                        payer -= c;
                        dfs(payers, payees, cnt + 1, minCnt);
                        payee -= c;
                        payer += c;
                    }

                }
            }
        }
        if (!enter) minCnt = min(minCnt, cnt);
    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        unordered_map<int, int> nums;
        vector<int> payers, payees;
        int c(0);
        int minCnt(INT_MAX);

        for (const vector<int>& ts: transactions) {
            if (!(m[ts[0]] += ts[2]))
                m.erase(ts[0]);
            if (!(m[ts[1]] -= ts[2]))
                m.erase(ts[1]);
        }

        for (const auto& p: m) {
            if (nums.count(-p.second)) {
                c++;
                if (!(nums[-p.second]--)) nums.erase(-p.second);
            } else {
                nums[p.second]++;
            }
        }

        for (const auto& p: nums) {
            if (p.first > 0) {
                for (int i = 0; i < p.second; ++i) payees.push_back(p.first);
            } else {
                for (int i = 0; i < p.second; ++i) payers.push_back(p.first);
            }
            //p.first > 0 ? payees.push_back(n) : payers.push_back(n);
        }

        //sort(payers.rbegin(), payers.rend());
        //sort(payees.begin(), payees.end());
        /*
        for (int v: payers) cout << v << " ";
        cout << endl;
        for (int v: payees) cout << v << " ";
        cout << endl;*/
        dfs(payers, payees, 0, minCnt);

        return minCnt + c;
    }
};
